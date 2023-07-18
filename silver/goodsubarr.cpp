#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
	int n; cin >> n;
	vector<int> jar(n+1);
	jar[0] = 0;
	for (int i = 1; i <= n; i++) {
		char c; cin >> c;
		jar[i] += jar[i-1] + int(c-'0');
	}

	map<int, ll> occ;
	occ[0] = 1;
	for (int i = 1; i <= n; i++) {
		jar[i] -= i;
		occ[jar[i]]++;
	}

	ll ans = 0;
	for (auto &[_,f] : occ) {
		ans += f * (f-1) / 2;
	}

	cout << ans << '\n';
	return 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
