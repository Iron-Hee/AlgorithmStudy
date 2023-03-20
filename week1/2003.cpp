#include <iostream>
#include <queue>
using namespace std;

int arr[10000];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int ans = 0, sum = 0;
	queue<int> Q;
	for (int i = 0; i < N; i++) {
		Q.push(arr[i]);
		sum += arr[i];
		if (sum == M) {
			ans += 1;
		}
		else if (sum > M) {
			while (!Q.empty() && sum > M) {
				sum -= Q.front();
				Q.pop();
			}
			if (sum == M) {
				ans += 1;
			}
		}
	}
	cout << ans;
	return 0;
}