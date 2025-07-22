#include <iostream>
#include <gmock/gmock.h>
using namespace testing;

class Cal {
public:
	int getSum(int a, int b) {
		return a+b;
	}

	int getSumSum(int a, int b, int c) {
		return a + b + c;
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


TEST(tc, tc1) {
	EXPECT_EQ(1, 1);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
