#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> edges[100001];
bool visit[100001];
int ans[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int s, e;
		cin >> s >> e;
		edges[s].push_back(e);
		edges[e].push_back(s);
	}
	queue<int> Q;
	Q.push(1);
	visit[1] = true;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int next : edges[cur]) {
			if (visit[next] == false) {
				Q.push(next);
				visit[next] = true;
				ans[next] = cur;
			}
		}
	}
	for (int i = 2; i <= N; i++)
		cout << ans[i] << '\n';
	return 0;
}