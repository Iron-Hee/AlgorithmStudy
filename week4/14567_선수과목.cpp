#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> edges[1001];
int in_degree[1001];
int semester[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		edges[s].push_back(e);
		in_degree[e]++;
	}
	int now = 1;
	queue<pair<int, int>> Q;
	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) {
			Q.push({ i, now });
			semester[i] = now;
		}
	}
	while (!Q.empty()) {
		auto cur = Q.front();
		now = cur.second;
		Q.pop();
		for (int next : edges[cur.first]) {
			in_degree[next]--;
			if (in_degree[next] == 0) {
				Q.push({ next, now + 1 });
				semester[next] = now + 1;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << semester[i] << ' ';
	}
	return 0;
}