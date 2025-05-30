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
	ifstream fin("angry.in");
	ofstream fout("angry.out");

	int n; fin >> n;
	vector<int> x(n);
	for (auto &el : x) fin >> el;
	sort(begin(x), end(x));

	vector<int> to_left(n), to_right(n);

	for (int i = 0; i < n-1; i++) {
		int rad = to_left[i] + 1, nxt = i+1;
		if (x[nxt] - x[i] > rad) {
			to_left[nxt] = x[nxt] - x[i];
		} else {
			while (nxt < n && x[nxt] - x[i] <= rad) {
				to_left[nxt] = rad;
				nxt++;
			}
			if (nxt == n) break;
			else i = nxt-2;
		}
	}

	for (int i = n-1; i > 0; i--) {
		int rad = to_right[i] + 1, pre = i-1;
		if (x[i] - x[pre] > rad) {
			to_right[pre] = x[i] - x[pre];
		} else {
			while (pre >= 0 && x[i] - x[pre] <= rad) {
				to_right[pre] = rad;
				pre--;
			}
			if (pre < 0) break;
			else i = pre+2;
		}
	}

	double ans = min_power(0.0, double(x[n-1] - x[0]), [&](double power) {
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

		if (r <= l || x[r] - x[l] <= 2.0 * power) return true;
		else return false;
	});

	fout << fixed << setprecision(1) << ans << endl;

	return 0;
}
