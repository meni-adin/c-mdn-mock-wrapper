
#include "mdn/mock_wrapper.hpp"

using namespace std;
using namespace testing;

unique_ptr<MWMock> mWMock;

int MWMock::Dummy() {
    constexpr int result = 42;
    return result;
}

extern "C" {
void *mdn_MW_malloc_(const char *callerName, size_t size) {
    return mWMock->malloc(callerName, size);
}

void *mdn_MW_realloc_(const char *callerName, void *ptr, size_t size) {
    return mWMock->realloc(callerName, ptr, size);
}
}

namespace {
ACTION(action_malloc) {
    return malloc(arg1);  // NOLINT
}

ACTION(action_realloc) {
    return realloc(arg1, arg2);  // NOLINT
}
}  // namespace

void MWMock::SetUp() {
    EXPECT_CALL(*mWMock, malloc(_, _))
        .WillRepeatedly(action_malloc());
    EXPECT_CALL(*mWMock, realloc(_, _, _))
        .WillRepeatedly(action_realloc());
}
