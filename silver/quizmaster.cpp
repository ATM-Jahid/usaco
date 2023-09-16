#include <bits/stdc++.h>
using namespace std;

const int MAXM = 1e5;
vector<int> factors[MAXM+1];

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	sort(begin(a), end(a));

	int count = 0;
	vector<int> freq(m+1);

	int r = 0, res = INT_MAX;
	for (int l = 0; l < n; l++) {
		while (r < n && count < m) {
			for (auto &x : factors[a[r]]) {
				if (x > m) break;
				if (++freq[x] == 1) count++;
			}
			r++;
		}

		if (count == m) {
			res = min(res, a[r-1] - a[l]);
		}

		for (auto &x : factors[a[l]]) {
			if (x > m) break;
			if (--freq[x] == 0) count--;
		}
	}

	if (res == INT_MAX) cout << "-1\n";
	else cout << res << '\n';
}

int main() {
	for (int i = 1; i <= MAXM; i++) {
		for (int j = i; j <= MAXM; j += i) {
			factors[j].push_back(i);
		}
	}

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
