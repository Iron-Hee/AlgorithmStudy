#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

long long rateOfDecay[200000];
long long expirationDate[200000];
bool isRemovable[200000];
bool desc(pair<long long, int> a, pair<long long, int> b) {
	return a.first > b.first;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, G, K;
	cin >> N >> G >> K;
	for (int i = 0; i < N; i++) {
		cin >> rateOfDecay[i] >> expirationDate[i] >> isRemovable[i];
	}
	long long low = 0;
	long long high = INT_MAX;
	long long ans = low;
	while (low + 1 < high) {
		long long mid = (low + high) / 2;
		vector<pair<long long, int>> germ;
		for (int i = 0; i < N; i++) {
			germ.push_back({rateOfDecay[i] * max((long long)1, mid - expirationDate[i]), i});
		}
		sort(germ.begin(), germ.begin() + N, desc);
		long long sum = 0;	//mid�Ͽ� K�� ���� �������� G�� ���� ����
		int count = K;
		for (int i = 0; i < N; i++) {
			if (count > 0 && isRemovable[germ[i].second]) {	//���� ��� �� �� ����
				count--;
			}
			else {	//�����ϱ� sum�� ����
				sum += germ[i].first;
			}
		}
		if (sum <= G) {	//T, ans����
			ans = max(ans, mid);
			low = mid;
		}
		else {	//F
			high = mid;
		}
	}
	cout << ans;
	return 0;
}