#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Array.hpp>

#include "array_test/basic.hpp"
#include "array_test/iterator.hpp"
#include "array_test/reverse_iterator.hpp"
#include "array_test/manipulation.hpp"

using namespace testing;


TEST(ArrayConstructor, LiteralConstructor) {
    aad::Array<int, 5> arr {1,2,3,4,5};
    ASSERT_THAT(arr[2],Eq(3));
}
TEST(ArrayConstructor, CopyConstructors) {
    aad::Array<int, 5> arr = {1,2,3,4,5};
    aad::Array<int, 5> arr2 = arr;
    ASSERT_THAT(arr2[2],Eq(arr[2]));
}

TEST(ArrayConstructor, AssignOperator) {
    aad::Array<int, 5> arr = {1,2,3,4,5};
    aad::Array<int, 5> arr2;
    arr2 = arr;
    ASSERT_THAT(arr2[2],Eq(arr[2]));
}