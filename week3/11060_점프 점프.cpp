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
		if (i > 1 && dist[i] == 0) continue;	//���� ��ġ���� ������ �ȵǸ� ���� ĭ Ȯ��
		for (int j = 1; (j <= arr[i] && i + j <= N); j++) {		//���� ��ġ�� ��ϵ� ���ڸ�ŭ �տ� Ȯ���ϸ� ǥ��
			if (dist[i + j] == 0 || (dist[i + j] != 0 && dist[i + j] > dist[i] + 1)) {	//��ϵ� �� ���ų�, ��ϵǾ��ִٸ� �� ������ ���� ���
				dist[i + j] = dist[i] + 1;
			}
		}
	}
	if (N != 1 && dist[N] == 0) cout << -1;
	else cout << dist[N];
	return 0;
}