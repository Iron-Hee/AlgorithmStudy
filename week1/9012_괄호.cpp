#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		stack<char> S;
		bool isRight = true;
		for (auto c : s) {
			if (c == '(')
				S.push(c);
			else {
				if (S.empty()) {
					isRight = false;
					break;
				}
				else {
					S.pop();
				}
			}
		}
		if (!isRight) cout << "NO\n";
		else cout << (S.empty() == true ? "YES\n" : "NO\n");
	}
	return 0;
}
