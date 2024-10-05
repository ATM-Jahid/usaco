#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int getSum(int l, int r) {
	cout << "? " << l << " " << r << endl;
	int sum; cin >> sum;
	return sum;
}

int main() {
	int n, t; cin >> n >> t;
	map<pii, pii> cache; // (l, r) -> (is_cached, sum)

	while (t--) {
		int k; cin >> k;

		int lo = 1, hi = n;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;

			if (!cache[{lo, mid}].first) {
				cache[{lo, mid}] = {1, getSum(lo, mid)};
			}
			int zcnt = (mid - lo + 1) - cache[{lo, mid}].second;

			if (zcnt >= k) {
				hi = mid;
				cache[{lo, mid}].second++;
			} else {
				lo = mid + 1;
				k -= zcnt;
			}
		}

		cout << "! " << lo << endl;
	}

	return 0;
}
