#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll first_true(ll lo, ll hi, function<bool(ll)> fn) {
	for (ll dif = hi - lo; dif > 0; dif /= 2) {
		while (lo + dif <= hi && !fn(lo + dif)) lo += dif;
	}
	return lo + 1;
}

int main() {
	ll n; cin >> n;

	auto upto = [&](ll cand) -> bool {
		ll cnt = 0;
		for (ll i = 1; i <= n && cand / i; i++) {
			cnt += min(cand / i, n);
		}
		return cnt >= (n*n + 1) / 2;
	};

	cout << first_true(0, n*n, upto) << endl;

	return 0;
}
