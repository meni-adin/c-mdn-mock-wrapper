set(TARGET_NAME mock_wrapper)

set(TARGET_SOURCES
    "mock_wrapper.cpp"
)

add_library(${TARGET_NAME} STATIC
    ${TARGET_SOURCES}
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_link_options(${TARGET_NAME} PRIVATE
        /OPT:NOREF
    )
endif()

target_link_libraries(${TARGET_NAME}
    GTest::gmock
)

target_include_directories(${TARGET_NAME}
    PUBLIC "include" ${INCLUDE_DIRECTORIES_TO_PROPAGATE}
)

cmake_language(CALL ${PROJECT_NAME}_set_target_cpp_compiler_flags ${TARGET_NAME})
