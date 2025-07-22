#include <iostream>
#include <gmock/gmock.h>

class Cal {
public:

	int getSumSum(int a, int b, int c) {
		return a + b + c;
	}
};

TEST(tc, tc1) {
	EXPECT_EQ(1, 1);
}


int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}