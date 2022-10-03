#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int area(pii a, pii b, pii c) {
	set<int> xs, ys;
	xs.insert({a.first, b.first, c.first});
	ys.insert({a.second, b.second, c.second});

	if (xs.size() == 1 || xs.size() == 3 ||
			ys.size() == 1 || ys.size() == 3) {
		return 0;
	} else if (xs.size() == 2 && ys.size() == 2) {
		int width = max({
			abs(b.first - a.first),
			abs(c.first - a.first),
			abs(c.first - b.first)});
		int height = max({
			abs(b.second - a.second),
			abs(c.second - a.second),
			abs(c.second - b.second)});
		return width * height;
	} else {
		return -1;
	}
}

int main() {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);

	int n; cin >> n;
	vector<pii> jar(n);
	for (auto &el : jar) cin >> el.first >> el.second;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				ans = max(ans, area(jar[i], jar[j], jar[k]));
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
