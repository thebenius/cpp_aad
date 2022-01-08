#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Array.hpp>

using namespace testing;

class ArrayReverseIterator: public testing::Test {
    public:
        aad::Array<int, 5> arr = {1,2,3,4,5};
};


TEST_F(ArrayReverseIterator, rbeginReturnsReverseIterator) {
    aad::Array<int, 5>::reverse_iterator it = arr.rbegin();
}

TEST_F(ArrayReverseIterator, BeginContainsLastElement) {
    ASSERT_THAT(*arr.rbegin(), Eq(arr[arr.size()-1]));
}

TEST_F(ArrayReverseIterator, PostfixIncrementationDeliversPreviousElement) {
    aad::Array<int, 5>::reverse_iterator it = arr.rbegin();
    ASSERT_THAT(*(it++), Eq(arr[arr.size()-1]));
    ASSERT_THAT(*it, Eq(arr[arr.size()-2]));
}

TEST_F(ArrayReverseIterator, PrefixIncrementationDeliversPreviousElement) {
    aad::Array<int, 5>::reverse_iterator it = arr.rbegin();
    ASSERT_THAT(*(++it), Eq(arr[arr.size()-2]));
}

TEST_F(ArrayReverseIterator, ComparingSameIteratorDeliversTrue) {
    ASSERT_THAT(arr.rbegin() == arr.rbegin(), true);
}
TEST_F(ArrayReverseIterator, ComparingDifferentIteratorsDeliversFalse) {
    ASSERT_THAT(arr.rbegin() == ++arr.rbegin(), false);
}

TEST_F(ArrayReverseIterator, IteratesThroughArray) {
    size_t i = arr.size()-1;
    for(auto it = arr.rbegin(); it != arr.rend();it++) {
        ASSERT_THAT(*it, Eq(arr.at(i)));
        i--;
    }
}

TEST_F(ArrayReverseIterator, IteratesThroughWholeArray) {
    size_t i = 0;
    for(auto it = arr.rbegin(); it != arr.rend();it++) {
        i++;
    }
    ASSERT_THAT(i,Eq(arr.size())); 
}

