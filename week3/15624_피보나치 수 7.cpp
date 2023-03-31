#include <iostream>
using namespace std;

int memo[1000001];
int fibo_top_down (int n) {
	if (n <= 1) {
		return n;
	}
	if (memo[n] != 0) return memo[n];
	memo[n] = (fibo_top_down(n - 1) + fibo_top_down(n - 2)) % 1000000007;
	return memo[n];
}
void fibo_bottom_up(int n) {
	if (n <= 1) {
		memo[n] = n;
		return;
	}
	for (int i = 2; i <= n; i++) {
		memo[i] = (memo[i - 1] + memo[i - 2]) % 1000000007;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	memo[0] = 0, memo[1] = 1;
	fibo_bottom_up(n);
	cout << memo[n];
	// cout << fibo_top_down(n);
	return 0;
}