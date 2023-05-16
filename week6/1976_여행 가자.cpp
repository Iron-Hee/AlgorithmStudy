#include <iostream>
#include <vector>
using namespace std;

int parent[201];
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void merge(int a, int b) {
	parent[find(a)] = find(b);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for(int i=1; i<=N; i++){
		for (int j = 1; j <= N; j++) {
			int isLinked;
			cin >> isLinked;
			if (isLinked > 0) {
				merge(i, j);
			}
		}
	}
	int root;
	for (int i = 1; i <= M; i++) {
		int place;
		cin >> place;
		if (i == 1) root = find(place);
		else if (root != find(place)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}