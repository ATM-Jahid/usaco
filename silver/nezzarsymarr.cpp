#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
	int n; cin >> n;
	vector<ll> d(2*n); 
	for (auto &x : d) cin >> x;
	sort(begin(d), end(d));

	ll cum = 0;
	vector<ll> a;
	for (int i = 2*n-1; i > 0; i -= 2) {
		if (d[i] != d[i-1] || (d[i] - cum) % (i + 1)) {
			cout << "NO\n";
			return 0;
		}
		ll num = (d[i] - cum) / (i + 1);
		a.push_back(num);
		cum += 2 * num;
	}
	a.erase(unique(begin(a), end(a)), end(a));

	if (a.size() == n && a[n-1] > 0) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
