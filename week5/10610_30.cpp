#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	bool isZeroExist = false;
	int tempSum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			isZeroExist = true;
		tempSum += s[i] - '0';
		tempSum %= 3;
	}
	if (!isZeroExist || tempSum != 0) {
		cout << "-1";
		return 0;
	}
	sort(s.begin(), s.end(), greater<int>());
	cout << s;
	return 0;
}