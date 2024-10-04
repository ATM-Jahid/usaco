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
	int n, p; cin >> n >> p;
	vector<int> k(n);
	for (auto &x : k) cin >> x;

	cout << first_true(0LL, (ll)1e18, [&](ll time) {
		ll prod = 0LL;
		for (int i = 0; i < n; i++) {
			prod += time / k[i];
			if (prod >= p) {
				return true;
			}
		}
		return false;
	}) << endl;

	return 0;
}
