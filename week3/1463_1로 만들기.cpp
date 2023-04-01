#include <iostream>
#include <algorithm>
using namespace std;

int dist[1000001];
void bottom_up(int num) {
	dist[1] = 0;
	for (int i = 2; i <= num; i++) {
		int temp1 = 1e7, temp2 = 1e7;
		int temp3 = dist[i - 1] + 1;
		if (i % 3 == 0) {
			temp1 = dist[i / 3] + 1;
		}
		if (i % 2 == 0) {
			temp2 = dist[i / 2] + 1;
		}
		dist[i] = min(min(temp1, temp2), temp3);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	bottom_up(N);
	cout << dist[N];
	return 0;
}