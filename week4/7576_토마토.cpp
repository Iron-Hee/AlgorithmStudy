#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int box[1000][1000];
bool visit[1000][1000];
int width, height;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	queue<pair<int, int>> Q;
	int day = 1;
	int unripen = 0;
	cin >> width >> height;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				Q.push({ i, j });
				visit[i][j] = true;
			}
			else if (box[i][j] == 0) {
				unripen++;
			}
		}
	}
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= height || ny < 0 || ny >= width) continue;
			if (visit[nx][ny] || box[nx][ny] == -1) continue;
			day = box[nx][ny] = box[cur.X][cur.Y] + 1;
			unripen--;
			visit[nx][ny] = true;
			Q.push({ nx, ny });
		}
	}
	if (unripen > 0) {
		cout << "-1";
	}
	else {
		cout << day - 1;
	}
	return 0;
}