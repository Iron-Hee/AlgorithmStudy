#include <iostream>
#include <algorithm>
using namespace std;

int lengthOfLAN[10000];
int K, N;
bool check(int length) {	//length�� �߶��� �� N���� �Ѵ��� check
	long long num = 0;
	for (int i = 0; i < K; i++) {
		num += lengthOfLAN[i] / length;
	}
	return (num >= N) ? true : false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> lengthOfLAN[i];
	}
	long long low = 1;
	long long high = *max_element(lengthOfLAN, lengthOfLAN + K);
	while (low + 1 < high) {
		long long mid = (low + high) / 2;	// ***overflow �߻����� ����***
		if (check(mid)) {
			if (check(mid + 1))	// T(mid)T
				low = mid;
			else {				// T(mid)F => mid�� ��
				cout << mid;
				return 0;
			}
		}
		else {
			if (check(mid - 1)) {	// T F(mid) => mid-1�� ��
				cout << mid - 1;
				return 0;
			}
			else {					// F F(mid)
				high = mid;
			}
		}
	}
	cout << (check(high) == true ? high : low);
	return 0;
}