cmake_minimum_required(VERSION 3.13)

project(cpp_aad)

include(FetchContent)
FetchContent_Declare(gtest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG release-1.11.0)
FetchContent_GetProperties(gtest)
if(NOT gtest_POPULATED)
    FetchContent_Populate(gtest)
    add_subdirectory(${gtest_SOURCE_DIR} ${gtest_BUILD_DIR})
endif()

add_compile_options(-g -O0)

add_executable(arrayTest tests/array_test.cpp)
target_link_libraries(arrayTest gtest_main gmock_main)
target_include_directories(arrayTest
    PUBLIC header
)