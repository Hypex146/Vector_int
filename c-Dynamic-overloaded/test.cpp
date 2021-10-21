#include "gtest/gtest.h"
#include "Vector.h"

using namespace HypexVector;

TEST(Constructors, ZeroParams_0) {
    Vector v;
    EXPECT_EQ(v.getSize(), 0);
}

TEST(Constructors, IntParam_0) {
    Vector v(1);
    EXPECT_EQ(v.getSize(), 1);
}

TEST(Constructors, PtrIntParam_0) {
    int mas[] = {1, 2, 3, 4};
    Vector v(4, mas);
    EXPECT_EQ(v.getSize(), 4);
}

TEST(Constructors, PtrIntParam_1) {
    int mas[] = {};
    Vector v(0, mas);
    EXPECT_EQ(v.getSize(), 0);
}

TEST(Constructors, Copy_0) {
    Vector v1;
    Vector v2(v1);
    EXPECT_EQ(v1.getSize(), v2.getSize());
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Constructors, Copy_1) {
    int mas[] = {1, 2, 3};
    Vector v1(3, mas);
    Vector v2(v1);
    EXPECT_EQ(v1.getSize(), v2.getSize());
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Constructors, ArrayIntParam_0) {
    Vector v({1, 2, 3, 4, 5});
    EXPECT_EQ(v.getSize(), 5);
}

TEST(Constructors, ArrayIntParam_1) {
    Vector v({});
    EXPECT_EQ(v.getSize(), 1);
}

TEST(Operators, AssignmentCopy_0) {
    Vector v1({1, 2, 3, 4});
    Vector v2;
    v2 = v1;
    EXPECT_EQ(v1.getSize(), v2.getSize());
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Operators, AssignmentCopy_1) {
    Vector v1;
    Vector v2;
    v2 = v1;
    EXPECT_EQ(v1.getSize(), v2.getSize());
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Operators, AssignmentArray_0) {
    Vector v1(7);
    Vector v2({1, 2, 3, 4});
    v1 = {1, 2, 3, 4};
    EXPECT_EQ(v1.getSize(), 4);
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Operators, AssignmentArray_1) {
    Vector v1;
    v1 = {777};
    Vector v2(777);
    EXPECT_EQ(v1.getSize(), 1);
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Operators, AssignmentArray_2) {
    Vector v1(7);
    Vector v2;
    v1 = {};
    EXPECT_EQ(v1.getSize(), 0);
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, GetSize_0) {
    Vector v;
    EXPECT_EQ(v.getSize(), 0);
}

TEST(Methods, GetSize_1) {
    Vector v(5);
    EXPECT_EQ(v.getSize(), 1);
}

TEST(Methods, GetSize_2) {
    Vector v({1, 2, 3});
    EXPECT_EQ(v.getSize(), 3);
}

TEST(Methods, Equals_0) {
    Vector v1;
    Vector v2;
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Equals_1) {
    Vector v1(4);
    Vector v2;
    EXPECT_EQ(v1.equals(v2), false);
}

TEST(Methods, Equals_2) {
    Vector v1(7);
    Vector v2(7);
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Equals_3) {
    Vector v1({1, 4, 9, -5});
    Vector v2({1, 4, 9, -5});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Equals_4) {
    Vector v1({1, 8, 3});
    Vector v2({1, 8, -3});
    EXPECT_EQ(v1.equals(v2), false);
}

TEST(Methods, Equals_5) {
    Vector v1({1, 6, 3});
    Vector v2(7);
    EXPECT_EQ(v1.equals(v2), false);
}

TEST(Operators, Equals_0) {
    Vector v1;
    Vector v2;
    EXPECT_EQ(v1 == v2, true);
}

TEST(Operators, Equals_1) {
    Vector v1(4);
    Vector v2;
    EXPECT_EQ(v1 == v2, false);
}

TEST(Operators, Equals_2) {
    Vector v1(7);
    Vector v2(7);
    EXPECT_EQ(v1 == v2, true);
}

TEST(Operators, Equals_3) {
    Vector v1({1, 4, 9, -5});
    Vector v2({1, 4, 9, -5});
    EXPECT_EQ(v1 == v2, true);
}

TEST(Operators, Equals_4) {
    Vector v1({1, 8, 3});
    Vector v2({1, 8, -3});
    EXPECT_EQ(v1 == v2, false);
}

TEST(Operators, Equals_5) {
    Vector v1({1, 6, 3});
    Vector v2(7);
    EXPECT_EQ(v1 == v2, false);
}

TEST(Methods, Summarize_0) {
    Vector v1({1, 6, 3});
    Vector v2(7);
    v1.summarize(v2);
    Vector v3({8, 6, 3});
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Methods, Summarize_1) {
    Vector v1({1, 5});
    Vector v2({7, 3, 9, 1});
    v1.summarize(v2);
    Vector v3({8, 8, 9, 1});
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Methods, Summarize_2) {
    Vector v1;
    Vector v2;
    v1.summarize(v2);
    Vector v3;
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Methods, Summarize_3) {
    Vector v1;
    Vector v2({8, 3, -8, 0, 5});
    v1.summarize(v2);
    Vector v3({8, 3, -8, 0, 5});
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Methods, Subtract_0) {
    Vector v1;
    Vector v2({8, 3, -8, 0, 5});
    v1.subtract(v2);
    Vector v3({-8, -3, 8, 0, -5});
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Methods, Subtract_1) {
    Vector v1(1);
    Vector v2({5, 2, -1});
    v1.subtract(v2);
    Vector v3({-4, -2, 1});
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Methods, Subtract_2) {
    Vector v1;
    Vector v2;
    v1.subtract(v2);
    Vector v3;
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Methods, Subtract_3) {
    Vector v1({4, 2, 7, 9});
    Vector v2({7, 4, 6, 2});
    v1.subtract(v2);
    Vector v3({-3, -2, 1, 7});
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Methods, Multiply_0) {
    Vector v1({4, -2, 7, -9});
    v1.multiply(3);
    Vector v2({12, -6, 21, -27});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Multiply_1) {
    Vector v1({4, -2, 7, -9});
    v1.multiply(0);
    Vector v2({0, 0, 0, 0});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Multiply_2) {
    Vector v1;
    v1.multiply(3);
    Vector v2;
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Multiply_3) {
    Vector v1({3, 0, 7, -1, 2});
    v1.multiply(-1);
    Vector v2({-3, 0, -7, 1, -2});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Divide_0) {
    Vector v1({3, 0, 7, -1, 2});
    v1.divide(-1);
    Vector v2({-3, 0, -7, 1, -2});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Divide_1) {
    Vector v1({3, 0, 7, 1, 2});
    v1.divide(2);
    Vector v2({1, 0, 3, 0, 1});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Divide_2) {
    Vector v1({3, 0, 7, 1, 2});
    EXPECT_THROW(v1.divide(0), std::invalid_argument);
}

TEST(Operators, Summarize_0) {
    Vector v1({1, 2, 3});
    Vector v2({3, 2, 1});
    Vector v3;
    v3 = v1 + v2;
    Vector v4({4, 4, 4});
    EXPECT_EQ(v3.equals(v4), true);
}

TEST(Operators, Summarize_1) {
    Vector v1({1, 2, 3, 5});
    Vector v2({3, 2, 1});
    Vector v3;
    v3 = v1 + v2;
    Vector v4({4, 4, 4, 5});
    EXPECT_EQ(v3.equals(v4), true);
}

TEST(Operators, Summarize_2) {
    Vector v1;
    Vector v2({3, -2, 1});
    Vector v3;
    v3 = v1 + v2;
    Vector v4({3, -2, 1});
    EXPECT_EQ(v3.equals(v4), true);
}

TEST(Operators, Subtract_0) {
    Vector v1;
    Vector v2({3, -2, 1});
    Vector v3;
    v3 = v1 - v2;
    Vector v4({-3, 2, -1});
    EXPECT_EQ(v3.equals(v4), true);
}

TEST(Operators, Subtract_1) {
    Vector v1({5, -3, 8, 4});
    Vector v2({3, -9, -2});
    Vector v3;
    v3 = v1 - v2;
    Vector v4({2, 6, 10, 4});
    EXPECT_EQ(v3.equals(v4), true);
}

TEST(Operators, Subtract_2) {
    Vector v1({1, 2});
    Vector v2;
    Vector v3;
    v3 = v1 - v2;
    Vector v4({1, 2});
    EXPECT_EQ(v3.equals(v4), true);
}

TEST(Operators, Multiply_0) {
    Vector v1({1, -2});
    Vector v2;
    v2 = v1 * 5;
    Vector v3({5, -10});
    EXPECT_EQ(v2.equals(v3), true);
}

TEST(Operators, Multiply_1) {
    Vector v1({1, -2, 4});
    Vector v2;
    v2 = v1 * 0;
    Vector v3({0, 0, 0});
    EXPECT_EQ(v2.equals(v3), true);
}

TEST(Operators, Multiply_2) {
    Vector v1;
    Vector v2;
    v2 = v1 * 5;
    Vector v3;
    EXPECT_EQ(v2.equals(v3), true);
}

TEST(Operators, Divide_0) {
    Vector v1({5, 3, -8, 4});
    Vector v2;
    v2 = v1 / 2;
    Vector v3({2, 1, -4, 2});
    EXPECT_EQ(v2.equals(v3), true);
}

TEST(Operators, Divide_1) {
    Vector v1({5, 3, 8, 4});
    Vector v2;
    v2 = v1 / -1;
    Vector v3({-5, -3, -8, -4});
    EXPECT_EQ(v2.equals(v3), true);
}

TEST(Operators, Divide_2) {
    Vector v1;
    Vector v2;
    v2 = v1 / -2;
    Vector v3;
    EXPECT_EQ(v2.equals(v3), true);
}

TEST(Operators, Divide_3) {
    Vector v1;
    Vector v2;
    EXPECT_THROW(v2 = v1 / 0, std::invalid_argument);
}

TEST(Operators, SelfSummarize_0) {
    Vector v1({1, 2, 3});
    Vector v2({3, 2, 1});
    v1 += v2;
    Vector v3({4, 4, 4});
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Operators, SelfSummarize_1) {
    Vector v1;
    Vector v2({3, 2, 1});
    v1 += v2;
    Vector v3({3, 2, 1});
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Operators, SelfSummarize_2) {
    Vector v1({7, 3, 9});
    Vector v2;
    v1 += v2;
    Vector v3({7, 3, 9});
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Operators, SelfSummarize_3) {
    Vector v1;
    Vector v2;
    v1 += v2;
    Vector v3;
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Operators, SelfSubtract_0) {
    Vector v1({3, 2, 1});
    Vector v2({1, 2, 3});
    v1 -= v2;
    Vector v3({2, 0, -2});
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Operators, SelfSubtract_1) {
    Vector v1;
    Vector v2({1, 2, 3});
    v1 -= v2;
    Vector v3({-1, -2, -3});
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Operators, SelfSubtract_2) {
    Vector v1({3, 2, 1});
    Vector v2;
    v1 -= v2;
    Vector v3({3, 2, 1});
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Operators, SelfSubtract_3) {
    Vector v1;
    Vector v2;
    v1 -= v2;
    Vector v3;
    EXPECT_EQ(v1.equals(v3), true);
}

TEST(Operators, SelfMultiply_0) {
    Vector v1({6, 3, -7, 3});
    v1 *= 4;
    Vector v2({24, 12, -28, 12});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Operators, SelfMultiply_1) {
    Vector v1;
    v1 *= 777;
    Vector v2;
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Operators, SelfMultiply_2) {
    Vector v1({2, 7, -5, 3, 7});
    v1 *= -1;
    Vector v2({-2, -7, 5, -3, -7});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Operators, SelfMultiply_3) {
    Vector v1({2, 7, -5, 3, 7});
    v1 *= 0;
    Vector v2({0, 0, 0, 0, 0});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Operators, SelfDivide_0) {
    Vector v1({2, 7, -5, 3, 7});
    v1 /= 2;
    Vector v2({1, 3, -2, 1, 3});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Operators, SelfDivide_1) {
    Vector v1;
    v1 /= 2;
    Vector v2;
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Operators, SelfDivide_2) {
    Vector v1({5, 3, -8, 9});
    v1 /= -1;
    Vector v2({-5, -3, 8, -9});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Operators, SelfDivide_3) {
    Vector v1({5, 3, -8, 9});
    EXPECT_THROW(v1 /= 0, std::invalid_argument);
}

TEST(Methods, Cut_0) {
    Vector v1({1, 2, 3, 4, 5});
    Vector v2 = v1.cut(0, 5);
    Vector v3({1, 2, 3, 4, 5});
    EXPECT_EQ(v2.equals(v3), true);
}

TEST(Methods, Cut_1) {
    Vector v1({1, 2, 3, 4, 5});
    Vector v2 = v1.cut(2, 2);
    Vector v3({3, 4});
    EXPECT_EQ(v2.equals(v3), true);
}

TEST(Methods, Cut_2) {
    Vector v1;
    Vector v2 = v1.cut(0, 0);
    Vector v3;
    EXPECT_EQ(v2.equals(v3), true);
}

TEST(Methods, Cut_3) {
    Vector v1;
    EXPECT_THROW(Vector v2 = v1.cut(0, 5), std::invalid_argument);
}

TEST(Methods, Cut_4) {
    Vector v1({1, 2, 3});
    EXPECT_THROW(Vector v2 = v1.cut(3, 1), std::invalid_argument);
}

TEST(Methods, Cut_5) {
    Vector v1({1, 2, 3});
    EXPECT_THROW(Vector v2 = v1.cut(0, 4), std::invalid_argument);
}

TEST(Methods, Cut_6) {
    Vector v1({1, 2, 3, 4, 5});
    Vector v2 = v1.cut(3, 0);
    Vector v3;
    EXPECT_EQ(v2.equals(v3), true);
}

TEST(Methods, Add_0) {
    Vector v1({1, 2, 3});
    v1.add(4);
    Vector v2({1, 2, 3, 4});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Add_1) {
    Vector v1;
    v1.add(777);
    Vector v2(777);
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Add_2) {
    Vector v1({1, 2, 3, -5});
    v1.add(-5);
    Vector v2({1, 2, 3, -5, -5});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Sort_0) {
    Vector v1({3, 1, 2, 6, 4, 5});
    v1.sort();
    Vector v2({1, 2, 3, 4, 5, 6});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Sort_1) {
    Vector v1({1, 2, 3, 4, 5, 6, 7, 8});
    v1.sort();
    Vector v2({1, 2, 3, 4, 5, 6, 7, 8});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Sort_2) {
    Vector v1({3, 1, -2, 6, 4, -5});
    v1.sort(true);
    Vector v2({6, 4, 3, 1, -2, -5});
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Sort_3) {
    Vector v1;
    v1.sort();
    Vector v2;
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, GetMax_0) {
    Vector v({-5, 4, 7, -8, -500, 8, 7, 2});
    EXPECT_EQ(v.getMax(), 8);
}

TEST(Methods, GetMax_1) {
    Vector v(777);
    EXPECT_EQ(v.getMax(), 777);
}

TEST(Methods, GetMax_2) {
    Vector v({777, 154, 56, 45, -55, -5894, 777, -777, 777, 8, -5, 0});
    EXPECT_EQ(v.getMax(), 777);
}

TEST(Methods, GetMax_3) {
    Vector v;
    EXPECT_THROW(v.getMax(), std::length_error);
}

TEST(Methods, GetMin_0) {
    Vector v({-5, 4, 7, -8, -500, 8, 7, 2});
    EXPECT_EQ(v.getMin(), -500);
}

TEST(Methods, GetMin_1) {
    Vector v(777);
    EXPECT_EQ(v.getMin(), 777);
}

TEST(Methods, GetMin_2) {
    Vector v({777, -5894, 56, 45, -55, -5894, 777, -777, 777, 8, -5, 0});
    EXPECT_EQ(v.getMin(), -5894);
}

TEST(Methods, GetMin_3) {
    Vector v;
    EXPECT_THROW(v.getMin(), std::length_error);
}

TEST(Methods, Clear_0) {
    Vector v1({1, 5, 3, 6, 8, 8, 5, 7, 8});
    v1.clear();
    Vector v2;
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Clear_1) {
    Vector v1(777);
    v1.clear();
    Vector v2;
    EXPECT_EQ(v1.equals(v2), true);
}

TEST(Methods, Clear_2) {
    Vector v1;
    v1.clear();
    Vector v2;
    EXPECT_EQ(v1.equals(v2), true);
}
