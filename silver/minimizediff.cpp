#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int first_true(int lo, int hi, function<bool(int)> fn) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (fn(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
	int n; ll k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	sort(begin(a), end(a));

	vector<ll> pref(n), suff(n);
	for (int i = 0; i < n; i++) {
		pref[i] = a[n-1] - a[i];
		if (i) pref[i] += pref[i-1];
	}
	for (int i = n-1; i >= 0; i--) {
		suff[i] = a[i] - a[0];
		if (i < n-1) suff[i] += suff[i+1];
	}

	cout << first_true(0, (int)pref[0], [&](int diff) {
		ll cost = (ll)1e15;
		for (int ii = 0; ii < n-1; ii++) {
			int xbot = a[ii], xtop = xbot + diff;
			int jj = distance(begin(a),
					upper_bound(begin(a), end(a), xtop));

			ll c1 = 0LL;
			c1 += pref[ii] - 1LL * (a[n-1] - xbot) * (ii+1);
			if (jj < n) c1 += suff[jj] - 1LL * (xtop - a[0]) * (n-jj);
			cost = min(cost, c1);
		}
		for (int jj = n-1; jj > 0; jj--) {
			int xtop = a[jj], xbot = xtop - diff;
			int ii = distance(begin(a),
					lower_bound(begin(a), end(a), xbot));
			ii--;

			ll c2 = 0LL;
			if (ii >= 0) c2 += pref[ii] - 1LL * (a[n-1] - xbot) * (ii+1);
			c2 += suff[jj] - 1LL * (xtop - a[0]) * (n-jj);
			cost = min(cost, c2);
		}

		if (cost > k) return false;
		else return true;
	}) << endl;

	return 0;
}
