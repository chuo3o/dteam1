#include <iostream>
#include <gmock/gmock.h>

class Cal {
public:

	int getSumSum(int a, int b, int c) {
		return a + b + c;
	}

	int getGop(int a, int b) {
		return a * b;
	}

	int getZegop(int a) {
		return a * a;
	}
};

TEST(tc, tc1) {
	EXPECT_EQ(1, 1);
}

TEST(tc, gop) {
    Cal cal;
    EXPECT_EQ(2, cal.getGop(1, 2));
    EXPECT_EQ(6, cal.getGop(2, 3));
    EXPECT_EQ(15, cal.getGop(3, 5));
    EXPECT_EQ(36, cal.getGop(4, 9));
}

TEST(tc, zegop) {
	Cal cal;
	EXPECT_EQ(1, cal.getZegop(1));
	EXPECT_EQ(4, cal.getZegop(2));
	EXPECT_EQ(9, cal.getZegop(3));
	EXPECT_EQ(16, cal.getZegop(4));
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}