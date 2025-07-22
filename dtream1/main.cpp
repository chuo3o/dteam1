#include <iostream>
#include "gmock/gmock.h"

using namespace testing;
class Cal {
public:
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

class CalTestFixture :public Test {
public:
	Cal cal;
};

TEST_F(CalTestFixture, gop) {
	EXPECT_EQ(2, cal.getGop(1, 2));
	EXPECT_EQ(6, cal.getGop(2, 3));
	EXPECT_EQ(15, cal.getGop(3, 5));
	EXPECT_EQ(36, cal.getGop(4, 9));
}

TEST_F(CalTestFixture, zegop) {
	EXPECT_EQ(1, cal.getZegop(1));
	EXPECT_EQ(4, cal.getZegop(2));
	EXPECT_EQ(9, cal.getZegop(3));
	EXPECT_EQ(16, cal.getZegop(4));
}

TEST_F(CalTestFixture, basic_cal_minus) {

	int actual, expected;
	actual = cal.getMinus(100, 10);
	expected = 100 - 10;
	EXPECT_EQ(expected, actual);
}

TEST_F(CalTestFixture, SumSum) {

	EXPECT_EQ(6, cal.getSumSum(1, 2, 3));
}

int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}