#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <Array.hpp>

using namespace testing;

class ArrayTest: public testing::Test {
    public:
        aad::Array<int, 5> arr = {1,2,3,4,5};
};

class ArrayIterator: public testing::Test {
    public:
        aad::Array<int, 5> arr = {1,2,3,4,5};
};

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

TEST_F(ArrayTest, GetSize) {
    ASSERT_THAT(arr.size(), Eq(5));
}

TEST_F(ArrayTest, SubscriptOperatorAdressesValues) {
    ASSERT_THAT(arr[3], Eq(4));
}

TEST_F(ArrayTest, DataDeliversPointerToValues) {
    int *data = arr.data();
    ASSERT_THAT(*(data+2), Eq(arr[2]));
}

TEST_F(ArrayTest, GetValueAt) {
    ASSERT_THAT(arr.at(3), Eq(4));
}

TEST_F(ArrayTest, GetExceptionAtoutOfBounds) {
    EXPECT_THROW(arr.at(5), std::out_of_range);
}

TEST_F(ArrayTest, FrontIsFirstElement) {
    ASSERT_THAT(arr.front(), Eq(arr[0]));
}

TEST_F(ArrayTest, BackIsLastElement) {
    ASSERT_THAT(arr.back(), Eq(arr[4]));
}

TEST_F(ArrayIterator, beginReturnsIterator) {
    aad::Array<int, 5>::iterator it = arr.begin();
}

TEST_F(ArrayIterator, BeginContainsFirstElement) {
    ASSERT_THAT(*arr.begin(), Eq(arr[0]));
}