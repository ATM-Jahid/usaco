#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	int n, k; cin >> n >> k;
	vector<int> jar(n);
	for (auto &el : jar) cin >> el;

	int ans = 1;
	sort(jar.begin(), jar.end());
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = i+1; j < n; j++) {
			if (jar[j] - jar[i] <= k) cnt++;
			else break;
		}
		ans = max(ans, cnt);
	}

	cout << ans << '\n';
	return 0;
}
