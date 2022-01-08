#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Array.hpp>

using namespace testing;


class Integer {
    public:
        int value;
        Integer(int value) {
            this->value = value;
        }
        void set(int value) {
            this->value = value;
        }
        int get() const {
            return value;
        }
};

class ArrayManipulation: public testing::Test {
    public:
        aad::Array<Integer, 5> arr = {Integer(1),Integer(2),Integer(3),Integer(4),Integer(5)};
};



TEST_F(ArrayManipulation, IteratorManipulatesArray) {
    for(auto it = arr.begin(); it != arr.end(); it++) {
        (*it).set(5);
        ASSERT_THAT((*it).get(),Eq(5));
    }
}

TEST_F(ArrayManipulation, ReverseIteratorManipulatesArray) {
    for(auto it = arr.rbegin(); it != arr.rend(); it++) {
        (*it).set(5);
        ASSERT_THAT((*it).get(),Eq(5));
    }
}
