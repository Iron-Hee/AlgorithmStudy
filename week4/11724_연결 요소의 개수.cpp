#include <iostream>
#include <vector>
using namespace std;

vector<int> edges[1001];
bool visit[1001];
int N, M;

void dfs(int cur_node) {
	visit[cur_node] = true;
	for (int next_node : edges[cur_node]) {
		if (!visit[next_node])
			dfs(next_node);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		edges[s].push_back(e);
		edges[e].push_back(s);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			ans++;
			dfs(i);
		}
	}
	cout << ans;
	return 0;
}