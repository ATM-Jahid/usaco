#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<ll> jar(n);
	for (auto &x : jar) cin >> x;
	sort(begin(jar), end(jar));

	ll mod = 1e9 + 7;
	for (int k = n-1; k > 0; k--) {
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		int l = 0, r = k;
		ll uplim = jar[0] + jar[k] + 1;
		while (l < r) {
			if (jar[l] + jar[r] < uplim) {
				for (int p = l+1; p < r+1; p++) {
					pq.push(jar[l] + jar[p]);
				}
				l++;
				uplim = jar[l] + jar[r];
			} else {
				r--;
			}
		}
		for (int i = 0; i < k; i++) {
			jar[i] = pq.top();
			pq.pop();
		}
		ll quotient = jar[0] / mod;
		for (int i = 0; i < k; i++) {
			jar[i] -= quotient * mod;
		}
	}

	cout << jar[0] << endl;
	return 0;
}
