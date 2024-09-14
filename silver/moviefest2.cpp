#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<pair<int, int>> movies(n);
	for (auto &[s, e] : movies) cin >> s >> e;
	sort(begin(movies), end(movies), [](auto &l, auto &r) {
		if (l.second == r.second) return l.first < r.first;
		else return l.second < r.second;
	});

	int cnt = 0;
	multiset<int> jar;
	for (auto &[s, e] : movies) {
		auto it = jar.upper_bound(s);
		if (it == jar.begin() && jar.size() == k) {
			continue;
		} else if (it == jar.begin()) {
			cnt++;
			jar.insert(e);
		} else {
			cnt++;
			jar.erase(prev(it));
			jar.insert(e);
		}
	}

	cout << cnt << endl;
	return 0;
}
