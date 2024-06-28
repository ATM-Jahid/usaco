#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;

	map<ll, int> events;
	ll l, r; set<ll> u;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		events[l]++; events[r+1]--;
		u.insert(l); u.insert(r+1);
	}

	vector<ll> uv(begin(u), end(u));
	int k = uv.size();

	vector<ll> res(n);
	for (int i = 1; i < k; i++) {
		res[events[uv[i-1]]-1] += uv[i] - uv[i-1];
		events[uv[i]] += events[uv[i-1]];
	}

	for (int i = 0; i < n; i++) cout << res[i] << ' ';
	cout << '\n';

	return 0;
}
