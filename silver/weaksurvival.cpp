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
		priority_queue<array<ll, 3>> pq;
		vector<ll> nx;
		for (int i = 0; i < k; i++) {
			pq.push({-jar[i]-jar[i+1], i, i+1});
		}
		for (int i = 0; i < k; i++) {
			ll v = pq.top()[0], l = pq.top()[1], r = pq.top()[2];
			nx.push_back(-v);
			pq.pop();
			if (r+1 < jar.size()) pq.push({-jar[l]-jar[r+1], l, r+1});
		}
		ll quotient = nx[0] / mod;
		for (int i = 0; i < k; i++) {
			nx[i] -= quotient * mod;
		}
		jar = nx;
	}

	cout << jar[0] << endl;
	return 0;
}
