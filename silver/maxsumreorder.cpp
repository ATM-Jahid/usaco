#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	sort(begin(a), end(a));

	vector<int> diff(n+1);
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		diff[l-1]++; diff[r]--;
	}
	for (int i = 1; i < n+1; i++) diff[i] += diff[i-1];
	if (!diff[n]) diff.pop_back();
	sort(begin(diff), end(diff));

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += 1LL * a[i] * diff[i];
	}
	cout << ans << endl;

	return 0;
}
