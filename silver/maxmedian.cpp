#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	
	sort(begin(a), end(a));
	int median = a[n/2];

	while (k) {
		auto it = upper_bound(begin(a), end(a), median);
		int nxv = *it, d = distance(begin(a), it), nel = d - n/2;

		if (it == end(a) || 1LL * (nxv - median) * nel > k) {
			median += k / nel;
			break;
		} else {
			k -= (nxv - median) * nel;
			median = nxv;
		}
	}

	cout << median << endl;
	return 0;
}
