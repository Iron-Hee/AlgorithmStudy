#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_NODE 1000
vector<int> edges[MAX_NODE + 1];
bool visit[MAX_NODE + 1];
queue<int> q;
int N, M, V;

void dfs(int cur_node) {
	visit[cur_node] = true;
	cout << cur_node << ' ';
	for (int next_node : edges[cur_node]) {
		if (!visit[next_node])
			dfs(next_node);
	}
}

void bfs(int start_node) {
	q.push(start_node);
	visit[start_node] = true;
	while (!q.empty()) {
		int cur_node = q.front();
		q.pop();
		cout << cur_node << ' ';
		for (int next_node : edges[cur_node]) {
			if (!visit[next_node]) {
				q.push(next_node);
				visit[next_node] = true;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		edges[node1].push_back(node2);
		edges[node2].push_back(node1);
	}
	for (int i = 1; i <= N; i++) {
		sort(edges[i].begin(), edges[i].end());
	}
	dfs(V);
	cout << '\n';
	for (int i = 1; i <= N; i++)
		visit[i] = false;
	bfs(V);
	return 0;
}