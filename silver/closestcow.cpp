#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int k, m, n; cin >> k >> m >> n;
	vector<pair<int, int>> grass(k);
	for (auto &[p, t] : grass) cin >> p >> t;
	vector<int> nhoj(m);
	for (auto &c : nhoj) cin >> c;

	sort(begin(grass), end(grass));
	sort(begin(nhoj), end(nhoj));

	vector<ll> pref(k); pref[0] = 1LL * grass[0].second;
	for (int i = 1; i < k; i++) pref[i] = pref[i-1] + grass[i].second;

	vector<pair<ll, ll>> inter(m+1); // (one, two) cow approach
	int l = 0;
	while (grass[l].first < nhoj[0]) l++;
	if (l > 0) inter[0] = {pref[l-1], 0};
	int r = k-1;
	while (grass[r].first > nhoj[m-1]) r--;
	if (r < k-1) inter[m] = {pref[k-1] - (r >= 0 ? pref[r] : 0), 0};

	for (int i = 1; i < m; i++) {
		int p1 = nhoj[i-1], p2 = nhoj[i], p3 = grass[l].first,
			vi = l, lb = -1;
		while (p1 < p3 && p3 < p2) {
			if (p3 - p1 < p2 - p3) lb = vi;
			vi++;
			p3 = grass[vi].first;
		}
		if (vi == l) continue;
		inter[i].second = pref[vi-1] - (l > 0 ? pref[l-1] : 0);

		if (lb == -1) { // if no patch belongs to p1
			inter[i].first = inter[i].second;
		} else {
			ll best = pref[lb] - (l > 0 ? pref[l-1] : 0); // leftbound
			best = max(best, inter[i].second - best); // rightbound

			r = lb + 1; // r = vi if no patch for p2
			while (l <= lb && r < vi) {
				int d12 = grass[r].first - grass[l].first,
					c1 = grass[l].first - p1,
					c2 = p2 - grass[r].first;
				if (d12 < c1 + c2) {
					best = max(best, pref[r] - (l > 0 ? pref[l-1] : 0));
					r++;
				} else {
					l++;
				}
			}
			inter[i].first = best;
		}

		// if one cow is optimal, don't use two cows
		if (inter[i].second == inter[i].first) inter[i].second = 0;
		l = vi;
	}

	sort(begin(inter), end(inter));

	vector<int> incr;
	for (auto &[a, b] : inter) {
		incr.push_back(a);
		if (b > a) incr.push_back(b-a); // (b-a) can be negative
	}
	sort(begin(incr), end(incr), greater<int>());

	ll ans = 0;
	if (n > incr.size()) n = incr.size();
	for (int i = 0; i < n; i++) ans += incr[i];
	cout << ans << endl;

	return 0;
}
