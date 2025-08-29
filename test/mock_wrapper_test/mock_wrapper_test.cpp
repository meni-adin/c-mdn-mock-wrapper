
#include <gmock/gmock.h>

#include "mdn/mock_wrapper.hpp"

using namespace testing;

class MockWrapperTest : public ::testing::Test {};

TEST_F(MockWrapperTest, Dummy) {
    const int dummy = MWMock::Dummy();
    ASSERT_EQ(dummy, 42);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
