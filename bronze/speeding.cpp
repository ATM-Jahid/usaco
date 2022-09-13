#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

	int n, m; cin >> n >> m;
	vector<int> road(100), bessie(100);
	for (int i = 0, run = 0; i < n; i++) {
		int p, q; cin >> p >> q;
		for (int j = run; j < p + run; j++) {
			road[j] = q;
		}
		run += p;
	}

	int ans = 0;
	for (int i = 0, run = 0; i < m; i++) {
		int p, q; cin >> p >> q;
		for (int j = run; j < p + run; j++) {
			bessie[j] = q;
			ans = max(ans, bessie[j]-road[j]);
		}
		run += p;
	}

	cout << ans << '\n';
	return 0;
}
