#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<pair<char, int>> jar(n);
	for (auto &el : jar) cin >> el.first >> el.second;
	sort(jar.begin(), jar.end(), [](auto &left, auto &right) {
		return left.second < right.second;
	});

	int ans = INT_MAX;
	for (auto x : jar) {
		int cnt = 0;
		for (auto y : jar) {
			if (y.first == 'G' && x.second < y.second) {
				cnt++;
			} else if (y.first == 'L' && x.second > y.second) {
				cnt++;
			}
		}
		ans = min(ans, cnt);
	}

	cout << ans << '\n';
	return 0;
}
