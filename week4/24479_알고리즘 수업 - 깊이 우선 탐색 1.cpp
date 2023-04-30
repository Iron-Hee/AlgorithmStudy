#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edges[100001];
int visit[100001];
int visitNum = 1;
void dfs(int cur_node) {
	for (int next_node : edges[cur_node]) {
		if (visit[next_node] == 0) {
			visit[next_node] = visitNum++;
			dfs(next_node);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, R;
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
		sort(edges[i].begin(), edges[i].end());

	visit[R] = visitNum++;
	dfs(R);
	for (int i = 1; i <= N; i++)
		cout << visit[i] << '\n';
	return 0;
}