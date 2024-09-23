#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int solve() {
	int n; cin >> n;
	vector<pii> ab(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		ab[i] = {x, y};
	}
	sort(begin(ab), end(ab));

	vector<int> suff_b(n);
	suff_b[n-1] = -1;
	for (int i = n-2; i >= 0; i--) {
		suff_b[i] = max(ab[i+1].second, suff_b[i+1]);
	}

	vector<pii> b(n);
	for (int i = 0; i < n; i++) b[i] = {ab[i].second, i};
	sort(begin(b), end(b));

	int best = INT_MAX;
	for (int i = n-1; i >= 0; i--) {
		int x = ab[i].first, y = suff_b[i];
		if (y > -1) best = min(best, abs(x - y));

		if (y < x) {
			pii lp = {y, -1}, hp = {x, INT_MAX};
			int ld = distance(begin(b),
					upper_bound(begin(b), end(b), lp)),
				hd = distance(begin(b),
					upper_bound(begin(b), end(b), hp));
			if (y == -1) ld = 0;
			for (int j = hd-1; j >= ld; j--) {
				if (b[j].second < i) {
					best = min(best, x - b[j].first);
					break;
				}
			}

			lp = {x, -1}, hp = {2*x-y, INT_MAX};
			ld = distance(begin(b),
				upper_bound(begin(b), end(b), lp));
			hd = distance(begin(b),
				upper_bound(begin(b), end(b), hp));
			if (y == -1) hd = n;
			for (int j = ld; j < hd; j++) {
				if (b[j].second < i) {
					best = min(best, b[j].first - x);
					break;
				}
			}
		}
	}

	cout << best << endl;
	return 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
