#include <iostream>
#include <gmock/gmock.h>

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
TEST_F(CalculatorFixture, TC1) {
	test(getSum(1, 2), 3);
}

TEST_F(CalculatorFixture, TC2) {
	test(getSum(1e8, 3e8), 4e8);
}

TEST_F(CalculatorFixture, TC3) {
	test(getSum(1U<<31, 1U<<31))
}

TEST(tc, tc1) {
	EXPECT_EQ(1, 1);
}


int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
