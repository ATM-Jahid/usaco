#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	int rbest = 0;
	for (int i = 0; i < n; i++) {
		int d = distance(begin(b),
				upper_bound(begin(b), end(b), a[i]));
		int minr = INT_MAX;
		if (d < m) minr = b[d] - a[i];
		if (d) minr = min(minr, a[i] - b[d-1]);
		rbest = max(rbest, minr);
	}
	cout << rbest << endl;

	return 0;
}
