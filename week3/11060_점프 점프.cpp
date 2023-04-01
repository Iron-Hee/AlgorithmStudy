#include <iostream>
using namespace std;

int arr[1001];
int dist[1001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	for (int i = 1; i < N; i++) {
		if (i > 1 && dist[i] == 0) continue;	//현재 위치에서 진행이 안되면 다음 칸 확인
		for (int j = 1; (j <= arr[i] && i + j <= N); j++) {		//현재 위치에 기록된 숫자만큼 앞에 확인하며 표시
			if (dist[i + j] == 0 || (dist[i + j] != 0 && dist[i + j] > dist[i] + 1)) {	//기록된 적 없거나, 기록되어있다면 더 작은걸 택해 기록
				dist[i + j] = dist[i] + 1;
			}
		}
	}
	if (N != 1 && dist[N] == 0) cout << -1;
	else cout << dist[N];
	return 0;
}