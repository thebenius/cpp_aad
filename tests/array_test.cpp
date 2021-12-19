#include <gtest/gtest.h>
#include <array.hpp>


TEST(ArrayTest, TestTest) {
    ASSERT_EQ(6, 5);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}