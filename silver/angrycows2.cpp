#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("angry.in");
	ofstream fout("angry.out");

	int n; fin >> n;
	vector<int> x(n);
	for (auto &el : x) {
		fin >> el;
		el *= 2;
	}
	sort(begin(x), end(x));

	vector<int> y = x;
	for (auto &el : y) el *= -1;
	reverse(begin(y), end(y));

	auto right_ok = [&](int bloc, int power, vector<int> &arr) {
		int ind = 0;
		while (bloc < arr[n-1]) {
			while (ind+1 < n && arr[ind+1] <= bloc + power) ind++;
			if (arr[ind] == bloc) {
				return false;
			}
			bloc = arr[ind];
			power -= 2;
		}
		return true;
	};

	auto power_ok = [&](int power) {
		// binary search on leftmost point
		// that blasts everyting on the right
		int l = x[0], r = x[n-1];
		while (l < r) {
			int m = l + (r - l) / 2;
			if (right_ok(m, power, x)) {
				r = m;
			} else {
				l = m + 1;
			}
		}

		// right_ok can do the job of left_ok
		// if we mirror array x about the origin
		if (right_ok(-l, power, y)) return true;
		else return false;
	};

	// binary search on min power
	int lo = 0, hi = int(2e9);
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (power_ok(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	fout << lo / 2 << '.' << (lo % 2 ? 5 : 0) << '\n';

	return 0;
}
