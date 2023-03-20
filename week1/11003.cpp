#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, L;
	cin >> N >> L;
	deque<pair<int, int>> DQ;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (i == 0) {
			DQ.push_back({ num, i });
		}
		else {
			if (DQ.front().second == i - L)
				DQ.pop_front();
			while (!DQ.empty() && DQ.back().first > num) {
				DQ.pop_back();
			}
			DQ.push_back({ num, i });
		}
		cout << DQ.front().first << ' ';
	}
	return 0;
}