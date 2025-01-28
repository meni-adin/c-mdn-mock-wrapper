
#include "mock_wrapper.hpp"

using namespace std;
using namespace testing;

unique_ptr<MWMock> mWMock;

extern "C" {
void *mw_malloc(const char *callerName, size_t size) {
    return mWMock->malloc(callerName, size);
}
}

ACTION(mallocAction) {
    return malloc(arg1);
}

void MWMock::SetUp() {
    EXPECT_CALL(*mWMock, malloc(_, _))
        .WillRepeatedly(mallocAction());
}
