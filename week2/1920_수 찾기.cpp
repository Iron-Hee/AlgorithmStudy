#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> M;
	sort(arr, arr + N);
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		int left = 0, right = N - 1;
		bool isExist = false;
		while (left < right) {
			int mid = (left + right) / 2;
			if (num < arr[mid])
				right = mid - 1;
			else if (num > arr[mid])
				left = mid + 1;
			else {
				isExist = true;
				break;
			}
		}
		if (left == right && arr[left] == num)
			isExist = true;
		cout << (isExist == true ? "1\n" : "0\n");
	}
	return 0;
}