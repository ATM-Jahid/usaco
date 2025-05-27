#include <bits/stdc++.h>
using namespace std;

int first_true(int lo, int hi, function<bool(int)> fn) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (fn(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &el : a) cin >> el;

	vector<vector<int>> res(n);
	int last_filled = 0;

	for (auto &el : a) {
		int ind = first_true(0, last_filled, [&](int guess) {
			if (res[guess].empty() || res[guess].back() < el) return true;
			else return false;
		});

		res[ind].push_back(el);
		last_filled = max(last_filled, ind);
	}

	for (int i = 0; i <= last_filled; i++) {
		for (auto &x : res[i]) cout << x << ' ';
		cout << '\n';
	}

	return 0;
}
