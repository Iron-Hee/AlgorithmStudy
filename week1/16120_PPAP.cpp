#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	stack<pair<char, int>> ppap;
	for (char cur : s) {
		if (cur == 'A') {
			if (!ppap.empty() && ppap.top().first == 'P' && ppap.top().second == 2) {	//가장 위가 {P, 2}면
				ppap.push({ cur, 3 });
			}
			else {
				cout << "NP";
				return 0;
			}
		}
		else {
			while (!ppap.empty() && ppap.top().first == 'A') {
				for (int i = 0; i < 3; i++)
					ppap.pop();
			}
			if (ppap.empty())
				ppap.push({ 'P', 1 });
			else
				ppap.push({ 'P', 2 });
		}
	}
	//최종적으로 ppap에는 {P, 1} 하나만 있어야 함
	if (ppap.size() == 1 && ppap.top().first == 'P')
		cout << "PPAP";
	else
		cout << "NP";
	return 0;
}
