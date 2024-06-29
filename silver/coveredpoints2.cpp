#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	ll l, r;
	map<ll, int> events;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		events[l]++; events[r+1]--;
	}

	// It must be res(n+1).
	// Otherwise, we might have to find res[-1],
	// which will lead to runtime errors.
	vector<ll> res(n+1);
	for (auto it = next(begin(events)); it != end(events); it++) {
		auto pit = prev(it);
		res[pit->second] += it->first - pit->first;
		it->second += pit->second;
	}

	for (int i = 1; i <= n; i++) {
		cout << res[i] << (i==n ? '\n' : ' ');
	}

	return 0;
}
