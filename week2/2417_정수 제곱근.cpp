#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n;
	cin >> n;
	long long low = 0, high = LLONG_MAX;
	while (low + 1 < high) {
		long long mid = (low + high) / 2;
		if (pow(mid, 2) >= n) {			// F|T(mid)인지 확인
			if (pow(mid - 1, 2) >= n) {
				high = mid;
			}
			else {
				cout << mid;
				return 0;
			}
		}
		else {							// F(mid)|T인지 확인
			if (pow(mid + 1, 2) >= n) {
				cout << mid + 1;
				return 0;
			}
			else {
				low = mid;
			}
		}
	}
	cout << 0;
	return 0;
}