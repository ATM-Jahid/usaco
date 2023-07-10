#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	sort(begin(s), end(s));
	cout << s << endl;
	return 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
