#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> jar(n);
	for (auto &x : jar) cin >> x;

	for (int i = 1; i < n; i++) {
		if (jar[i-1] < jar[i] - m) {
			jar[i-1] = jar[i] - m;
		}
		if (jar[i] < jar[i-1] - m) {
			jar[i] = jar[i-1] - m;
		}
	}

	for (int i = n-1; i > 0; i--) {
		if (jar[i-1] < jar[i] - m) {
			jar[i-1] = jar[i] - m;
		}
		if (jar[i] < jar[i-1] - m) {
			jar[i] = jar[i-1] - m;
		}
	}

	for (auto &x : jar) cout << x << ' ';
	cout << endl;

	return 0;
}
