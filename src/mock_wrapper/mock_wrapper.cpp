
#include "mock_wrapper.hpp"

using namespace std;
using namespace testing;

unique_ptr<MWMock> mWMock;

extern "C" {
void *mw_malloc(const char *callerName, size_t size) {
    return mWMock->malloc(callerName, size);
}

void *mw_realloc(const char *callerName, void *ptr, size_t size) {
    return mWMock->realloc(callerName, ptr, size);
}
}

ACTION(action_malloc) {
    return malloc(arg1);
}

ACTION(action_realloc) {
    return realloc(arg1, arg2);
}

void MWMock::SetUp() {
    EXPECT_CALL(*mWMock, malloc(_, _))
        .WillRepeatedly(action_malloc());
    EXPECT_CALL(*mWMock, realloc(_, _, _))
        .WillRepeatedly(action_realloc());
}
