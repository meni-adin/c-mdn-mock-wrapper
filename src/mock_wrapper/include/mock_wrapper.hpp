
#ifndef MOCK_WRAPPER_HPP
#define MOCK_WRAPPER_HPP

#include <gmock/gmock.h>

#include "mock_wrapper.h"

class MWMock {
public:
    void SetUp();
    MOCK_METHOD((void *), malloc, (const char *, size_t));
};

extern unique_ptr<MWMock> mWMock;

#endif  // MOCK_WRAPPER_HPP
