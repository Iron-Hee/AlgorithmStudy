#include <iostream>
#include <algorithm>
using namespace std;

bool isNotCover[1001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, L;
	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		int location;
		cin >> location;
		isNotCover[location] = true;
	}
	int ans = 0;
	for (int i = 1; i <= 1000; i++) {
		if (isNotCover[i] == true) {
			ans++;
			for (int j = i; (j < i + L && j <= 1000); j++) {
				isNotCover[j] = false;
			}
		}
	}
	cout << ans;
	return 0;
}