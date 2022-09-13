#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> c(n), a(n);
	for (auto &x : c) cin >> x;
	for (auto &x : a) cin >> x;

	int carry;
	for (int i = 1; i < n; i++) {
		carry = min(c[i]-a[i], a[i-1]);
		a[i-1] -= carry;
		a[i] += carry;
	}

	for (auto &x : a) cout << x << ' ';
	cout << '\n';
	return 0;
}
