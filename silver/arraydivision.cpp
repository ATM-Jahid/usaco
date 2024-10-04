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
	int n, k; cin >> n >> k;
	vector<int> x(n);
	for (auto &el : x) cin >> el;

	cout << first_true(0LL, (ll)1e15, [&](ll max_sum) {
		int subarr = 0;
		ll run = 0;

		for (int i = 0; i < n; i++) {
			if (x[i] > max_sum) return false;
			if (run + x[i] > max_sum) {
				subarr++;
				run = 0;
				i--;
			} else {
				run += x[i];
			}
		}
		if (run) subarr++;

		return subarr <= k;
	}) << endl;

	return 0;
}
