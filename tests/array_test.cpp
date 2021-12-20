#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Array.hpp>

using namespace testing;

class ArrayTest: public testing::Test {
    public:
        aad::Array<int, 5> arr;
};

TEST_F(ArrayTest, CopyConstructors) {
    arr[2] = 5;
    aad::Array<int, 5> arr2 = arr;
    ASSERT_THAT(arr2[2],Eq(arr[2]));
}

TEST_F(ArrayTest, AssignOperator) {
    arr[2] = 5;
    aad::Array<int, 5> arr2;
    arr2 = arr;
    ASSERT_THAT(arr2[2],Eq(arr[2]));
}

TEST_F(ArrayTest, GetSize) {
    ASSERT_THAT(arr.size(), Eq(5));
}

TEST_F(ArrayTest, SubscriptOperatorAdressesValues) {
    arr[3] = 156;
    ASSERT_THAT(arr[3], Eq(156));
}

TEST_F(ArrayTest, DataDeliversPointerToValues) {
    int *data = arr.data();
    ASSERT_THAT(*(data+2), Eq(arr[2]));
}

TEST_F(ArrayTest, GetValueAt) {
    arr[3] = 156;
    ASSERT_THAT(arr.at(3), Eq(156));
}

TEST_F(ArrayTest, GetExceptionAtoutOfBounds) {
    EXPECT_THROW(arr.at(5), std::out_of_range);
}

TEST_F(ArrayTest, FrontIsFirstElement) {
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    ASSERT_THAT(arr.front(), Eq(arr[0]));
}
TEST_F(ArrayTest, BackIsLastElement) {
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    ASSERT_THAT(arr.back(), Eq(arr[4]));
}