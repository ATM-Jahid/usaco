#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);

	int n; cin >> n;
	vector<int> rad(n);
	for (auto &el : rad) cin >> el;

	int ans = INT_MAX, cum;
	for (int i = 0; i < n; i++) {
		cum = 0;
		for (int j = 0; j < n; j++) {
			cum += rad[j] * ((j - i + n) % n);
		}
		ans = min(ans, cum);
	}

	cout << ans << '\n';
	return 0;
}
