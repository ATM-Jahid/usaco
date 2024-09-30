#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int last_true(int lo, int hi, function<bool(int)> fn) {
	for (int dif = hi - lo; dif > 0; dif /= 2) {
		while (lo + dif <= hi && fn(lo + dif)) lo += dif;
	}
	return lo;
}

int solve() {
	int N, Tc, Tm; cin >> N >> Tc >> Tm;
	vector<ll> a(N), b(N), c(N);
	for (int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];

	auto works = [&](int cand_tc, int cand_tm) -> bool {
		for (int i = 0; i < N; i++) {
			if (a[i] * cand_tc + b[i] * cand_tm > c[i]) {
				return false;
			}
		}
		return true;
	};

	auto cost = [&](int cand_tc, int cand_tm) -> int {
		if (cand_tc == 0 || cand_tm == 0) return INT_MAX;
		return (Tc - cand_tc) + (Tm - cand_tm);
	};

	auto gtc = [&](int cand_tc) -> int {
		int best_tm = last_true(0, Tm, [&](int cand_tm) {
			return works(cand_tc, cand_tm);
		});
		return cost(cand_tc, best_tm);
	};

	// gtc(n-1) > gtc(n) is not monotonic
	// thus it doesn't work
	int best_tc = last_true(1, Tc, [&](int cand_tc) {
		return gtc(cand_tc-1) > gtc(cand_tc);
	});

	for (int i = 0; i <= 5; i++) cout << gtc(i) << ' ';
	cout << endl;
	/*cout << best_tc << endl;*/
	/*cout << last_true(0, Tm, [&](int cand_tm) {*/
	/*	return works(best_tc, cand_tm);*/
	/*}) << endl;*/
	/*cout << works(3, 1) << endl;*/
	/*cout << (gtc(2) > gtc(3)) << endl;*/

	cout << gtc(best_tc) << endl;
	return 0;
}

int main() {
	int T; cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
