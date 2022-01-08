#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Array.hpp>

using namespace testing;

class ArrayIterator: public testing::Test {
    public:
        aad::Array<int, 5> arr = {1,2,3,4,5};
};


TEST_F(ArrayIterator, beginReturnsIterator) {
    aad::Array<int, 5>::iterator it = arr.begin();
}

TEST_F(ArrayIterator, BeginContainsFirstElement) {
    ASSERT_THAT(*arr.begin(), Eq(arr[0]));
}

TEST_F(ArrayIterator, PostfixIncrementationDeliversNextElement) {
    aad::Array<int, 5>::iterator it = arr.begin();
    ASSERT_THAT(*(it++), Eq(arr[0]));
    ASSERT_THAT(*it, Eq(arr[1]));
}

TEST_F(ArrayIterator, PrefixIncrementationDeliversNextElement) {
    aad::Array<int, 5>::iterator it = arr.begin();
    ASSERT_THAT(*(++it), Eq(arr[1]));
}

TEST_F(ArrayIterator, ComparingSameIteratorDeliversTrue) {
    ASSERT_THAT(arr.begin() == arr.begin(), true);
}
TEST_F(ArrayIterator, ComparingDifferentIteratorsDeliversFalse) {
    ASSERT_THAT(arr.begin() == ++arr.begin(), false);
}

TEST_F(ArrayIterator, IteratesThroughArray) {
    size_t i = 0;
    for(int element: arr) {
        ASSERT_THAT(element, Eq(arr.at(i)));
        i++;
    }
}

TEST_F(ArrayIterator, IteratesThroughWholeArray) {
    size_t i = 0;
    for(auto it = arr.begin(); it != arr.end();it++) {
        i++;
    }
    ASSERT_THAT(i,Eq(arr.size()));
}
