#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int parent[100001];
tuple<int, int, int> namu[100001];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a); b = find(b);
	parent[b] = a;
}

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	int a_x1, b_x1;
	tie(a_x1, std::ignore, std::ignore) = a;
	tie(b_x1, std::ignore, std::ignore) = b;
	return a_x1 < b_x1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q, x1, x2, y;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> x1 >> x2 >> y;
		namu[i] = make_tuple(x1, x2, i);
		parent[i] = i;
	}
	sort(namu + 1, namu + N + 1, cmp);

	int left, right, idx;
	tie(left, right, idx) = namu[1];
	for (int i = 2; i <= N; i++) {
		int cmp_l, cmp_r, cmp_idx;
		tie(cmp_l, cmp_r, cmp_idx) = namu[i];
		if (right < cmp_l) {
			left = cmp_l; right = cmp_r; idx = cmp_idx;
		}
		else {
			merge(idx, cmp_idx);
			if (right < cmp_r) {
				left = cmp_l; right = cmp_r; idx = cmp_idx;
			}
		}
	}
	while (Q--) {
		int idx1, idx2;
		cin >> idx1 >> idx2;
		if (find(idx1) == find(idx2)) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}