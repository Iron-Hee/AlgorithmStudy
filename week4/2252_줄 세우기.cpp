#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> edges[32001];
int in_degree[32001];

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
	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) {
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int cur = Q.front();
		cout << cur << ' ';
		Q.pop();
		for (int end : edges[cur]) {
			in_degree[end]--;
			if (in_degree[end] == 0) Q.push(end);
		}
	}
	return 0;
}