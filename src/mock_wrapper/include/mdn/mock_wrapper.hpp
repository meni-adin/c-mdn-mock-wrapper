
#ifndef MOCK_WRAPPER_HPP
#define MOCK_WRAPPER_HPP

#include <gmock/gmock.h>

#include "mock_wrapper.h"

class MWMock {
public:
    static int  Dummy();
    static void SetUp();
    MOCK_METHOD((void *), malloc, (const char *, size_t));
    MOCK_METHOD((void *), realloc, (const char *, void *, size_t));
};

extern std::unique_ptr<MWMock> mWMock;

#endif  // MOCK_WRAPPER_HPP
