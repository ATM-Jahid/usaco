#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, m, q; cin >> n >> m >> q;
	vector<int> a(n), b(m);
	for (auto &x : a) cin >> x;
	for (auto &y : b) cin >> y;

	ll altsum_a = 0LL;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) altsum_a += a[i];
		else altsum_a -= a[i];
	}
	vector<ll> bpref(m+1);
	for (int i = 0; i < m; i++) {
		if (i % 2 == 0) bpref[i+1] = bpref[i] + b[i];
		else bpref[i+1] = bpref[i] - b[i];
	}

	vector<ll> fnj(m-n+1);
	for (int j = 0; j <= m-n; j++) {
		if (j % 2 == 0) fnj[j] = bpref[n+j] - bpref[j];
		else fnj[j] = bpref[j] - bpref[n+j];
	}
	sort(begin(fnj), end(fnj));

	int l = 0, r = 0, x = 0;
	for (int i = -1; i < q; i++) {
		if ((r-l+1) % 2 == 1 && r % 2 == 1) altsum_a += -x;
		else if ((r-l+1) % 2 == 1 && r % 2 == 0) altsum_a += x;

		auto it = lower_bound(begin(fnj), end(fnj), altsum_a);
		if (it == end(fnj)) {
			cout << llabs(*prev(it) - altsum_a) << endl;
		} else {
			ll ans = llabs(*it - altsum_a);
			if (it != prev(end(fnj)))
				ans = min(ans, llabs(*next(it) - altsum_a));
			if (it != begin(fnj))
				ans = min(ans, llabs(*prev(it) - altsum_a));
			cout << ans << endl;
		}

		if (i != q-1) {
			cin >> l >> r >> x;
			l--; r--;
		}
	}

	return 0;
}
