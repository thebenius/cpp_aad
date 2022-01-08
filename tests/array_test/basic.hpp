#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Array.hpp>

using namespace testing;

class BasicArrayTest: public testing::Test {
    public:
        aad::Array<int, 5> arr = {1,2,3,4,5};
};


TEST_F(BasicArrayTest, GetSize) {
    ASSERT_THAT(arr.size(), Eq(5));
}

TEST_F(BasicArrayTest, SubscriptOperatorAdressesValues) {
    ASSERT_THAT(arr[3], Eq(4));
}

TEST_F(BasicArrayTest, DataDeliversPointerToValues) {
    int *data = arr.data();
    ASSERT_THAT(*(data+2), Eq(arr[2]));
}

TEST_F(BasicArrayTest, GetValueAt) {
    ASSERT_THAT(arr.at(3), Eq(4));
}

TEST_F(BasicArrayTest, GetExceptionAtoutOfBounds) {
    EXPECT_THROW(arr.at(5), std::out_of_range);
}

TEST_F(BasicArrayTest, FrontIsFirstElement) {
    ASSERT_THAT(arr.front(), Eq(arr[0]));
}

TEST_F(BasicArrayTest, BackIsLastElement) {
    ASSERT_THAT(arr.back(), Eq(arr[4]));
}

TEST_F(BasicArrayTest, ComparingSameObjectIsTrue) {
    ASSERT_THAT(arr==arr, Eq(true));
}

TEST_F(BasicArrayTest, ComparingDifferentObjectsIsFalse) {
    aad::Array<int, 5> arrcpy = arr;
    ASSERT_THAT(arrcpy==arr, Eq(false));
}