#include <bits/stdc++.h>
using namespace std;

double min_power(double lo, double hi, function<bool(double)> fn) {
	while ((hi - lo) > 1e-3) {
		double mid = (lo + hi) / 2;
		if (fn(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return hi;
}

int main() {
	// ifstream cin("angry.in");
	// ofstream cout("angry.out");

	int n; cin >> n;
	vector<int> x(n);
	for (auto &el : x) cin >> el;
	sort(begin(x), end(x));

	vector<int> to_right(n), to_left(n);

	// not correct
	for (int i = n-2; i >= 0; i--) {
		to_right[i] = max(to_right[i+1] + 1, x[i+1] - x[i]);
	}

	// not correct
	for (int i = 1; i < n; i++) {
		to_left[i] = max(to_left[i-1] + 1, x[i] - x[i-1]);
	}

	// for (auto &el : x) cout << el << ' ';
	// cout << endl;
	// for (auto &el : to_right) cout << el << ' ';
	// cout << endl;
	// for (auto &el : to_left) cout << el << ' ';
	// cout << endl;

	double ans = min_power(0.0, double(x[n-1]-x[0]), [&](double power) {
		int l, r;
		for (l = 0; l < n-1; l++) {
			if (double(to_left[l]) > max(0.0, power - 1.0)) {
				break;
			}
		}
		l--;
		for (r = n-1; r > 0; r--) {
			if (double(to_right[r]) > max(0.0, power - 1.0)) {
				break;
			}
		}
		r++;

		if (r <= l || x[r]-x[l] <= 2.0 * power) return true;
		else return false;
	});

	cout << fixed << setprecision(1) << ans << endl;

	return 0;
}
