#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> edges[10001];
bool visit[10001];
int dist[10001];
int maxDist, maxIndex;

void dfs(int cur_node) {
	visit[cur_node] = true;
	for (auto next_node : edges[cur_node]) {
		if (!visit[next_node.first]) {
			dist[next_node.first] = dist[cur_node] + next_node.second;
			if (maxDist < dist[next_node.first]) {
				maxDist = dist[next_node.first];
				maxIndex = next_node.first;
			}
			dfs(next_node.first);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		edges[s].push_back({ e, w });
		edges[e].push_back({ s, w });
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
		dist[i] = 0;
	}
	dfs(maxIndex);
	cout << maxDist;
	return 0;
}