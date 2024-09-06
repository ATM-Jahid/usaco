#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<ll> a(n), d(m);
	vector<int> l(m), r(m), x(k), y(k);
	for (auto &x : a) cin >> x;
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i] >> d[i];
		l[i]--; r[i]--;
	}
	for (int i = 0; i < k; i++) {
		cin >> x[i] >> y[i];
		x[i]--; y[i]--;
	}

	vector<int> diff1(m+1);
	for (int i = 0; i < k; i++) {
		diff1[x[i]]++;
		diff1[y[i]+1]--;
	}
	for (int i = 1; i < m+1; i++) diff1[i] += diff1[i-1];
	for (int i = 0; i < m; i++) d[i] *= diff1[i];

	vector<ll> diff2(n+1);
	for (int i = 0; i < m; i++) {
		diff2[l[i]] += d[i];
		diff2[r[i]+1] -= d[i];
	}
	for (int i = 1; i < n+1; i++) diff2[i] += diff2[i-1];
	for (int i = 0; i < n; i++) a[i] += diff2[i];
	for (auto &x : a) cout << x << ' ';
	cout << endl;

	return 0;
}
