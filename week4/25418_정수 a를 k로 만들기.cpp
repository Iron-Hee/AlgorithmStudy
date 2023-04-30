#include <iostream>
#include <queue>
using namespace std;

int opNum[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, K;
	cin >> A >> K;
	queue<int> Q;
	Q.push(A);
	opNum[A] = 1;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		int op1 = cur + 1;
		if (op1 <= K && opNum[op1] == 0) {
			opNum[op1] = opNum[cur] + 1;
			Q.push(op1);
		}
		int op2 = cur * 2;
		if (op2 <= K && opNum[op2] == 0) {
			opNum[op2] = opNum[cur] + 1;
			Q.push(op2);
		}
		if (opNum[K] != 0)
			break;
	}
	cout << opNum[K] - 1;
	return 0;
}