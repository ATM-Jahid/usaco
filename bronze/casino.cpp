#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> jar(m, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> jar[j][i];
		}
	}

	ll pot = 0;
	for (int j = 0; j < m; j++) {
		sort(begin(jar[j]), end(jar[j]));
		for (int i = 0; i < n; i++) {
			pot += 1LL * (2*i+1-n) * jar[j][i];
		}
	}

	cout << pot << '\n';
	return 0;
}

int main() {
	int T; cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
