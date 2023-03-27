#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n;
	cin >> n;
	long long low = 0, high = pow(2, 32);
	long long ans = 0;
	while (low + 1 < high) {
		long long mid = (low + high) / 2;
		if (pow(mid, 2) >= n) {			// F|T(mid)인지 확인
			high = mid;
			ans = mid;
		}
		else {							// F(mid)|T인지 확인
			low = mid;
		}
	}
	if (n == 0) {
		ans = 0;
	}
	cout << ans;
	return 0;
}