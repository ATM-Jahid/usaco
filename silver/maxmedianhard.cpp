#include <bits/stdc++.h>
using namespace std;

int last_true(int lo, int hi, function<bool(int)> fn) {
	lo--;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (fn(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	return lo;
}

int main() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	cout << last_true(0, (int)2e5, [&](int median) {
		vector<int> pref(n);
		for (int i = 0; i < n; i++) {
			pref[i] = (a[i] < median ? -1 : 1);
			if (i) pref[i] += pref[i-1];
		}

		int mnp = 0, mxdif = pref[k-1];
		for (int i = k; i < n; i++) {
			mnp = min(mnp, pref[i-k]);
			mxdif = max(mxdif, pref[i] - mnp);
		}

		if (mxdif > 0) return true;
		else return false;
	}) << endl;

	return 0;
}
