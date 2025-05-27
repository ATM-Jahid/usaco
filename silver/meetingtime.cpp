#include <bits/stdc++.h>
using namespace std;

double min_time(double lo, double hi, function<bool(double)> fn) {
	while ((hi - lo) > 1e-7) {
		double mid = (lo + hi) / 2;
		if (fn(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return lo;
}

int main() {
	int n; cin >> n;
	vector<pair<int, int>> posvel(n);
	for (int i = 0; i < n; i++) cin >> posvel[i].first;
	for (int i = 0; i < n; i++) cin >> posvel[i].second;

	cout << fixed << setprecision(7) << min_time(0.0, 1e9, [&](double time) {
		double min_rbound = 1e9, max_lbound = 0.0;
		for (auto &[x, v] : posvel) {
			min_rbound = min(min_rbound, x + v * time);
			max_lbound = max(max_lbound, x - v * time);
		}

		if (min_rbound < max_lbound) return false;
		else return true;
	}) << endl;

	return 0;
}
