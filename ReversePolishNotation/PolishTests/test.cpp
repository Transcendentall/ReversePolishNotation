#include "pch.h"
#include "gtest/gtest.h"
using namespace std;

TEST(Test1, TestName1) {
	char input[] = "1+1";
	ASSERT_DOUBLE_EQ(2, ReversePolishNotationFunction(input));
}
TEST(Test2, TestName2) {
	char input[] = "2 + 3";
	ASSERT_DOUBLE_EQ(5, ReversePolishNotationFunction(input));
}
TEST(Test3, TestName3) {
	char input[] = "(2 * 3) + (4 * 5)";
	ASSERT_DOUBLE_EQ(26, ReversePolishNotationFunction(input));
}
TEST(Test4, TestName4) {
	char input[] = "2 / (3 - (4 + (5 * 6)))";
	ASSERT_DOUBLE_EQ(0, ReversePolishNotationFunction(input));
}
TEST(Test5, TestName5) {
	char input[] = "(1+2)*4+3";
	ASSERT_DOUBLE_EQ(15, ReversePolishNotationFunction(input));
}
TEST(Test6, TestName6) {
	char input[] = "1*2*3*4*5";
	ASSERT_DOUBLE_EQ(120, ReversePolishNotationFunction(input));
}
TEST(Test7, TestName7) {
	char input[] = "8*(5-6)";
	ASSERT_DOUBLE_EQ(-8, ReversePolishNotationFunction(input));
}
TEST(Test8, TestName8) {
	char input[] = "(1-3)*(1-4)";
	ASSERT_DOUBLE_EQ(6, ReversePolishNotationFunction(input));
}
TEST(Test9, TestName9) {
	char input[] = "1+2+3+4+5+6+7+8+9+0";
	ASSERT_DOUBLE_EQ(45, ReversePolishNotationFunction(input));
}
TEST(Test10, TestName10) {
	char input[] = "0/8";
	ASSERT_DOUBLE_EQ(0, ReversePolishNotationFunction(input));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}