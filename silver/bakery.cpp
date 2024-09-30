#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll last_true(ll lo, ll hi, function<bool(ll)> fn) {
	for (ll dif = hi - lo; dif > 0; dif /= 2) {
		while (lo + dif <= hi && fn(lo + dif)) lo += dif;
	}
	return lo;
}

int solve() {
	ll N, Tc, Tm; cin >> N >> Tc >> Tm;
	vector<ll> a(N), b(N), c(N);
	for (int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];

	cout << (Tc + Tm) - last_true(2, Tc + Tm, [&](ll z) -> bool {
		ll xtr = 1, xtl = z - 1;

		for (int i = 0; i < N; i++) {
			ll dd = a[i] - b[i];
			if (dd == 0 && z > c[i] / a[i]) {
				return false;
			}

			if (dd > 0) {
				xtl = min(xtl, (c[i] - b[i]*z) / dd);
			} else if (dd < 0) {
				xtr = max(xtr, (- c[i] + b[i]*z - dd - 1) / (- dd));
			}
		}

		ll ytr = z - xtr, ytl = z - xtl;
		if (xtr <= xtl && xtr <= Tc && ytl <= Tm) {
			return true;
		}
		return false;
	}) << endl;

	return 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
