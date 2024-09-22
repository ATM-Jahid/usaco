#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> sorted_a = a;
	sort(begin(sorted_a), end(sorted_a));

	int sum = 0, k = n;
	for (int i = 0; i < n; i++) {
		if (sum + sorted_a[i] > m) {
			k = i;
			break;
		} else {
			sum += sorted_a[i];
		}
	}

	if (k == n) {
		cout << "1\n";
	} else if (k == 0) {
		cout << n+1 << endl;
	} else if (sum - sorted_a[k-1] + a[k] <= m) {
		cout << n-k << endl;
	} else {
		cout << n-k+1 << endl;
	}

	return 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
