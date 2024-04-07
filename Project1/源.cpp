#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define INIT_MAX 10000
using namespace std;

int MAXsub(int a[INIT_MAX], int left, int right) {
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
}

int main() {
	int num;
	int input[INIT_MAX];
	//cout << "输入序列个数：" << endl;
	cin >> num;
	//cout << "输入序列的每个数字：" << endl;
	for (int k = 0; k < num; k++) {
		cin >> input[k];
	}
	cout << MAXsub(input, 0, num - 1) << endl;
	system("pause");
	return 0;

}

