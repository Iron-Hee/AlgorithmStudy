#include <iostream>
using namespace std;

int arr[50];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int S;
	cin >> S;
	int over = -1;
	while (S && over < N - 1) {
		int maxIndex = 0;
		int maxNum = -1;
		for (int i = over + 1; i <= min(over + 1 + S, N - 1); i++) {
			if (maxNum < arr[i]) {
				maxNum = arr[i];
				maxIndex = i;
			}
		}
		if (maxIndex > over + 1) {
			for (int i = maxIndex; i > over + 1; i--) {
				int temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
			}
			S -= maxIndex - (over + 1);
		}
		over++;
	}
	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
	return 0;
}