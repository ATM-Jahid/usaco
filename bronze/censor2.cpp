#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);

	string s, t, c;
	cin >> s >> t;

	for (int i = 0; i < s.size(); i++) {
		c += s[i];
		if (c.size() >= t.size() && c.substr(c.size() - t.size()) == t) {
			c.resize(c.size() - t.size());
		}
	}

	cout << c << '\n';
	return 0;
}
