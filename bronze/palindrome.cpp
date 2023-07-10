#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n, k; cin >> n >> k;
	map<char, int> reserve;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		reserve[c]++;
	}
	//cout << k << " palindromes of size " << n / k << endl;

	int pairs = 0, singles = 0;
	for (auto &el : reserve) {
		if (el.second % 2) singles++;
		pairs += el.second / 2;
	}
	//cout << "pairs = " << pairs << " ; singles = " << singles << endl;

	for (int len = 1; len <= n/k; len++) {
		int singles_needed, pairs_needed;
		if (len % 2) {
			singles_needed = k;
			pairs_needed = (len-1)/2 * k;
		} else {
			singles_needed = 0;
			pairs_needed = len/2 * k;
		}
		//cout << "need " << pairs_needed << " pairs and " << singles_needed << " singles\n";

		if (pairs_needed > pairs) {
			cout << len-1 << '\n';
			return 0;
		}
		if (singles_needed > singles) {
			if (singles_needed - singles > 2 * (pairs - pairs_needed)) {
				cout << len-1 << '\n';
				return 0;
			}
		}
	}

	cout << n/k << '\n';
	return 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
