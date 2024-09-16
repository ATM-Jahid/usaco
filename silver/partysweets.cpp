#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> b(n), g(m);
	for (auto &x : b) cin >> x;
	for (auto &x : g) cin >> x;
	sort(begin(b), end(b));
	sort(begin(g), end(g));

	if (b[n-1] > g[0]) {
		cout << "-1\n";
		return 0;
	}

	long long sweets = 0;
	for (int i = 0; i < n; i++) sweets += 1LL * m * b[i];
	for (int i = 1; i < m; i++) sweets += 1LL * (g[i] - b[n-1]);
	if (b[n-1] < g[0]) sweets += 1LL * (g[0] - b[n-2]);

	cout << sweets << endl;
	return 0;
}
