#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n; cin >> n;
	vector<array<int, 3>> jar(n);
	for (int i = 0; i < n; i++) {
		cin >> jar[i][0] >> jar[i][1];
		if (jar[i][0] < jar[i][1]) swap(jar[i][0], jar[i][1]);
		jar[i][2] = i + 1;
	}
	sort(begin(jar), end(jar), [](auto &l, auto &r) {
		if (l[0] == r[0]) return l[1] > r[1];
		else return l[0] < r[0];
	});

	vector<int> ans(n, -1);
	array<int, 3> pref = jar[0];
	for (auto &x : jar) {
		if (pref[0] < x[0] && pref[1] < x[1]) {
			ans[x[2]-1] = pref[2];
		}
		if (x[1] < pref[1]) pref = x;
	}

	for (auto &x : ans) cout << x << ' ';
	cout << endl;

	return 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
