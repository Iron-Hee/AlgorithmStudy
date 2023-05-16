#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int u, v, cost;
	edge(int u_, int v_, int cost_) : u(u_), v(v_), cost(cost_) {};
	edge() : u(0), v(0), cost(0) {};
	bool operator< (const edge& e) const { return cost < e.cost; };
};

char gender[1001];
int p[1001];
bool check[1001];

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}
void merge(int a, int b) {
	p[find(a)] = find(b);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		p[i] = i;
	for (int i = 1; i <= N; i++) {
		cin >> gender[i];
	}
	vector<edge> edges;	//남초, 여초 연결된 edge만 저장
	int ans = 0, univ_cnt = 0;
	while (M--) {
		int u, v, d;
		cin >> u >> v >> d;
		if (gender[u] == gender[v]) continue;
		edges.push_back(edge(u, v, d));
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++) {
		int u, v, d;
		u = edges[i].u; v = edges[i].v; d = edges[i].cost;
		u = find(u); v = find(v);
		if (u == v) continue;
		if (check[u] == false) {
			check[u] = true; univ_cnt++;
		}
		if (check[v] == false) {
			check[v] = true; univ_cnt++;
		}
		merge(u, v);
		ans += d;
	}
	if (univ_cnt < N) {
		cout << "-1";
		return 0;
	}
	cout << ans;
	return 0;

}