#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<pair<int, int>> movies(n);
	for (auto &[s, e] : movies) cin >> s >> e;

	sort(begin(movies), end(movies), [](auto &l, auto &r) {
		if (l.second == r.second) return l.first < r.first;
		else return l.second < r.second;
	});

	int p = movies[0].first, cnt = 0;
	for (auto &[s, e] : movies) {
		if (s < p) continue;
		cnt++;
		p = e;
	}

	cout << cnt << endl;
	return 0;
}
