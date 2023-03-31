#include <iostream>
#include <climits>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> data;
int A, C, B, N;
long long low = 0, high = (long long)INT_MAX;
long long ans = high;
long long mid;

long long calculate() {
	if (mid == 0) return 0;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		tie(A, C, B) = ::data[i];
		if (mid >= A) {
			sum += (min(mid, (long long)C) - A) / B + 1;
		}
	}
	return sum;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A >> C >> B;
		::data.push_back({ A, C, B });
	}
	while (low + 1 < high) {
		mid = (low + high) / 2;
		long long result = calculate();
		if (result % 2 == 1) {
			high = mid;
			ans = min(ans, mid);
		}
		else {
			low = mid;
		}
	}
	long long freq = 0;

	if (ans == (long long)INT_MAX + 1)
		cout << "NOTHING";
	else {
		cout << ans << ' ';
		mid = ans;
		long long temp = calculate();
		mid -= 1;
		long long temp2 = calculate();
		freq = temp - temp2;
		cout << freq;
	}
	return 0;
}