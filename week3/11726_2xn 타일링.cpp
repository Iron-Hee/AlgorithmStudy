#include <iostream>
using namespace std;

int ways[1001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	ways[1] = 1;
	ways[2] = 2;
	for (int i = 3; i <= n; i++) {
		ways[i] = (ways[i - 2] + ways[i - 1]) % 10007;
	}
	cout << ways[n];
	return 0;
}