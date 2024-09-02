#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n; cin >> n;
	vector<pair<int, int>> pos(n);
	for (auto &el : pos) {
		cin >> el.first >> el.second;
	}
	sort(begin(pos), end(pos), [](auto &l, auto &r) {
		if (l.second == r.second) return l.first < r.first;
		else return l.second < r.second;
	});

	set<int> used, cand;

	for (auto &el : pos) {
		int l = el.first, r = el.second;

		if (used.find(l) == used.end()) {
			used.insert(l);
			if (cand.find(l) != cand.end()) cand.erase(cand.find(l));
			if (used.find(l+1) == used.end()) cand.insert(l+1);
		} else {
			auto it = cand.lower_bound(l);
			if (*it > r) {
				cout << "No\n";
				return 0;
			}
			used.insert(*it);
			cand.erase(it);
			if (used.find(*it+1) == used.end()) cand.insert(*it+1);
		}
	}

	cout << "Yes\n";
	return 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
