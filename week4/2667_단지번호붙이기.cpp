#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

char board[25][25];
bool visit[25][25];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	queue<pair<int, int>> Q;
	vector<int> houseVec;
	int danzi = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != '0' && visit[i][j] == false) {
				int houseNum = 0;
				danzi++;
				Q.push({ i, j });
				visit[i][j] = true;
				while (!Q.empty()) {
					auto cur = Q.front();
					Q.pop();
					houseNum++;
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (board[nx][ny] == '0' || visit[nx][ny]) continue;
						Q.push({ nx, ny });
						visit[nx][ny] = true;
					}
				}
				houseVec.push_back(houseNum);
			}
		}
	}
	cout << danzi << '\n';
	sort(houseVec.begin(), houseVec.end());
	for (int num : houseVec) {
		cout << num << '\n';
	}
	return 0;
}