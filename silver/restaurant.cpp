#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	vector<int> pos;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		pos.push_back(a[i]);
		pos.push_back(b[i]);
	}
	sort(begin(pos), end(pos));
	vector<int> cust(pos.size());

	for (int i = 0; i < n; i++) {
		int d1 = distance(begin(pos),
				lower_bound(begin(pos), end(pos), a[i]));
		int d2 = distance(begin(pos),
				lower_bound(begin(pos), end(pos), b[i]));
		cust[d1]++;
		cust[d2]--;
	}

	int ans = cust[0];
	for (int i = 1; i < cust.size(); i++) {
		cust[i] += cust[i-1];
		ans = max(ans, cust[i]);
	}
	cout << ans << '\n';

	return 0;
}
