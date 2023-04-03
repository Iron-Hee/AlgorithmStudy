#include <iostream>
#include <algorithm>
using namespace std;

int wine[10001];
int ans[10001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> wine[i];

	ans[1] = wine[1];
	if (n >= 2) {
		ans[2] = ans[1] + wine[2];
		for (int i = 3; i <= n; i++) {
			ans[i] = max(max(ans[i - 1], ans[i - 3] + wine[i - 1] + wine[i]), ans[i - 2] + wine[i]);
		}
	}
	cout << ans[n];
	return 0;
}