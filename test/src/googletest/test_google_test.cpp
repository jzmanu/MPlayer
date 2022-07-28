/**
 * 测试GoogleTest基础用法
 */
#include <iostream>
#include "gtest/gtest.h"

int add(int a, int b) {
    return a + b;
}

TEST(add, zero) {
    EXPECT_EQ(0, add(0, 0)) << "yes";
}

TEST(add, positive) {
    EXPECT_EQ(3, add(1, 2)) << "yes";
}

