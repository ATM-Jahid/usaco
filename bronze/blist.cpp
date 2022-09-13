#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);

	int n; cin >> n;
	vector<int> s(n), t(n), b(n), jar(1001);
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> t[i] >> b[i];
		for (int j = s[i]; j < t[i]; j++)  {
			jar[j] += b[i];
		}
	}

	int ans = 0;
	for (auto &el : jar) ans = max(ans, el);
	cout << ans << '\n';
	return 0;
}
