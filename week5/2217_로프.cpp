#include <iostream>
#include <algorithm>
using namespace std;

int limit[100000];

bool cmp(int a, int b) {
	return a > b;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> limit[i];
	sort(limit, limit + N, cmp);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, limit[i] * (i + 1));
	}
	cout << ans;
	return 0;
}