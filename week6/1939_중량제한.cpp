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

int p[100001];
int startPoint, endPoint;

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

bool merge(int a, int b) {
	p[find(a)] = find(b);
	if (find(startPoint) == find(endPoint)) return true;
	else return false;
}

bool cmp(edge a, edge b) {
	return a.cost > b.cost;
}
int main(void) {
	int N, M;
	vector<edge> edges;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		p[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b, weightLimit;
		cin >> a >> b >> weightLimit;
		edges.push_back(edge(a, b, weightLimit));
	}
	sort(edges.begin(), edges.end(), cmp);
	cin >> startPoint >> endPoint;

	for (int i = 0; i < M; i++) {
		int u, v, cost;
		u = edges[i].u; v = edges[i].v; cost = edges[i].cost;
		if (merge(u, v)) {
			cout << cost;
			return 0;
		}
	}
}