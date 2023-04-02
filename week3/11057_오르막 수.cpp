#include <iostream>
using namespace std;

int ways[1001][10];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 0; i < 10; i++)
		ways[0][i] = 1;
	for (int i = 1; i <= N; i++)
		ways[i][0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 9; j++) {
			ways[i][j] = (ways[i][j - 1] + ways[i - 1][j]) % 10007;
		}
	}
	cout << ways[N][9];
	return 0;
}