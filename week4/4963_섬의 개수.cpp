#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int w, h;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		queue<pair<int, int>> Q;
		int** board = new int* [h];
		bool** visit = new bool* [h];
		int island = 0;

		for (int i = 0; i < h; i++) {
			board[i] = new int[w];
			visit[i] = new bool[w];
			for (int j = 0; j < w; j++) {
				visit[i][j] = false;
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == 1 && visit[i][j] == false) {
					Q.push({ i, j });
					visit[i][j] = true;
					island++;
					//bfs
					while (!Q.empty()) {
						auto cur = Q.front();
						Q.pop();
						for (int dir = 0; dir < 8; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
							if (board[nx][ny] == 0 || visit[nx][ny]) continue;
							Q.push({ nx, ny });
							visit[nx][ny] = true;
						}
					}
				}
			}
		}
		cout << island << '\n';

		delete[] board;
	}
	return 0;
}