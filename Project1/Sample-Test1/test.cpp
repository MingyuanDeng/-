//#include "pch.h"
//
//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}

#include "pch.h"

int MAXsub(int a[], int left, int right) {
	int sum = 0;
	if (left == right)
		sum = a[left] > 0 ? a[left] : 0;
	else {
		int mid;
		mid = (left + right) / 2;
		int leftsum = MAXsub(a, left, mid);
		int rightsum = MAXsub(a, mid + 1, right);

		int sl = 0;
		int lefts = 0;
		for (int i = mid; i >= left; i--) {
			lefts += a[i];
			if (lefts > sl)
				sl = lefts;
		}

		int sr = 0;
		int rights = 0;
		for (int i = mid + 1; i <= right; i++) {
			rights += a[i];
			if (rights > sr)
				sr = rights;
		}
		sum = sr + sl;
		if (sum < leftsum)
			sum = leftsum;
		if (sum < rightsum)
			sum = rightsum;
	}
	return sum;
};

// 定义测试用例

TEST(MaxSubarrayTest, BasicTest0) {
	int input1[] = { -3,-2,-1,0};

	EXPECT_EQ(MAXsub(input1, 0,3 ), 0);

}
TEST(MaxSubarrayTest, BasicTest1) {
    int input1[] = { 1, 2, 3, 4, 5 };

    EXPECT_EQ(MAXsub(input1, 0, 4), 15);

}
TEST(MaxSubarrayTest, BasicTest2) {
	int input1[] = { -2,-1,0,1,2 };

	EXPECT_EQ(MAXsub(input1, 0, 4),3);
}


TEST(MaxSubarrayTest, BasicTest3) {
	int input1[] = { 3,5,6,8,-6,-5,10 };

	EXPECT_EQ(MAXsub(input1, 0, 6),22 );
}
TEST(MaxSubarrayTest, BasicTest4) {
	int input1[] = { -2,11,-4,13,-5,-2};

	EXPECT_EQ(MAXsub(input1, 0, 5), 20);
}

int main(int argc, char** argv) {
    // 初始化 Google Test 框架
    ::testing::InitGoogleTest(&argc, argv);
    // 运行所有测试用例
    return RUN_ALL_TESTS();
}