#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int ans = 0;
	stack<char> S;
	char prev = '(';
	for (auto c : s) {
		if (c == '(') {
			ans += 1;
			S.push(c);
		}
		else {
			if (prev == '(') {
				ans -= 1;
				S.pop();
				ans += S.size();
			}
			else {
				S.pop();
			}
		}
		prev = c;
	}
	cout << ans;
	return 0;
}
