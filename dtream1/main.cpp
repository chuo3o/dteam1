#include <iostream>
#include <gmock/gmock.h>
using namespace testing;


using namespace testing;
class Cal {
public:

	int getSum(int a, int b) {
		return a+b;
	}

	int getDivide(int a, int b) {
		return a / b;
	}

	int getSumSum(int a, int b, int c) {
		return a + b + c;
	}

	int getGop(int a, int b) {
		return a * b;
	}

	int getZegop(int a) {
		return a * a;
	}

	int getMinus(int a, int b)
	{
		return a - b;
	}
};

class CalculatorFixture: public Test {
public:
	Cal cal;
	void test(int expected, int actual) {
		EXPECT_EQ(expected, actual);
	}
};
TEST_F(CalculatorFixture, GetSumTC1) {
	test(cal.getSum(1, 2), 3);
}

TEST_F(CalculatorFixture, GetSumTC2) {
	test(cal.getSum(1e8, 3e8), 4e8);
}

TEST_F(CalculatorFixture, GetSumTC3) {
	test(cal.getSum(1<<30, -(1<<30)), 0);
}

TEST_F(CalculatorFixture, gop) {
	EXPECT_EQ(2, cal.getGop(1, 2));
	EXPECT_EQ(6, cal.getGop(2, 3));
	EXPECT_EQ(15, cal.getGop(3, 5));
	EXPECT_EQ(36, cal.getGop(4, 9));
}

TEST_F(CalculatorFixture, zegop) {
	EXPECT_EQ(1, cal.getZegop(1));
	EXPECT_EQ(4, cal.getZegop(2));
	EXPECT_EQ(9, cal.getZegop(3));
	EXPECT_EQ(16, cal.getZegop(4));
}

TEST_F(CalculatorFixture, basic_cal_minus) {

	int actual, expected;
	actual = cal.getMinus(100, 10);
	expected = 100 - 10;
	EXPECT_EQ(expected, actual);
}

TEST_F(CalculatorFixture, SumSum) {
	EXPECT_EQ(6, cal.getSumSum(1, 2, 3));
}

int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}
