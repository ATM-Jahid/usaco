#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);

	string s, t;
	cin >> s >> t;
	int del_len = t.size(), pos = 0, found;

	while (1) {
		found = s.find(t, pos);
		if (found != string::npos) {
			s.erase(found, del_len);
			pos = max(0, found - del_len);
		} else {
			break;
		}
	}

	cout << s << '\n';
	return 0;
}
