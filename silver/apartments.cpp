#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	sort(begin(a), end(a));
	sort(begin(b), end(b));

	int cnt = 0, p = 0;
	for (int i = 0; i < m; i++) {
		if (p == n) break;
		if (b[i]-k <= a[p] && a[p] <= b[i]+k) {
			cnt++;
			p++;
		} else if (a[p] < b[i]-k) {
			p++;
			i--;
		}
	}

	cout << cnt << endl;
	return 0;
}
