#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define X first
#define Y second

int board[20][20];
int dist[20][20];
bool visit[20][20];
int N, shark_x, shark_y;
int size = 2, condition = 2, ans = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool cmp(pair<int, int> a, pair<int, int>b) {	// �ּ� �Ÿ� ���� ���� ������ ��, �����ϴ� �Լ�
	if (a.X == b.X) {
		return a.Y < b.Y;
	}
	return a.X < b.X;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				shark_x = i;
				shark_y = j;
			}
		}
	}
	int iter = 0;
	while (true) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				visit[i][j] = false;
				dist[i][j] = -1;
			}
		vector<pair<int, int>> prey;
		queue<pair<int, int>> Q;
		bool isPreyFound = false;
		int min_dist = 0;
		Q.push({ shark_x, shark_y });
		visit[shark_x][shark_y] = true;
		dist[shark_x][shark_y] = 0;

		while (!Q.empty()) {
			auto cur = Q.front();
			Q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;	//���� ���� ���
				if (visit[nx][ny] || board[nx][ny] > ::size) continue;	//�̹� �湮�߰ų� �� ū ����� ����
				if (board[nx][ny] > 0 && board[nx][ny] < ::size) {	//���� �������
					if (isPreyFound == false) {	//���� ���� �������� �߰ߵǾ��ٸ�
						isPreyFound = true;
						min_dist = dist[cur.X][cur.Y] + 1;
					}
					else if (min_dist < dist[cur.X][cur.Y] + 1) continue;	//���� ���� �Ÿ����� �ָ� �ִ� ���̶�� �н�
					prey.push_back({ nx, ny });
				}
				Q.push({ nx, ny });
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				visit[nx][ny] = true;
			}
		}
		if (prey.empty())	//���� �� �ִ� ����� ����
			break;
		sort(prey.begin(), prey.end(), cmp);
		board[shark_x][shark_y] = 0;
		shark_x = prey[0].X;
		shark_y = prey[0].Y;
		board[shark_x][shark_y] = 9;
		condition--;
		if (condition == 0) {
			::size++;
			condition = ::size;
		}
		ans += min_dist;
		/*
		cout << "after " << ++iter << " iteration : (" << shark_x << ", " << shark_y << ") size : " << ::size << " ans : " << ans << "\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << board[i][j] << ' ';
			}
			cout << "\n";
		}
		cout << "\n";
		*/
	}
	cout << ans;
	return 0;
}