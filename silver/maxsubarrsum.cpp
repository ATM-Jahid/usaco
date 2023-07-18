#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;

	ll pref, jmin, ans;
	cin >> pref; ans = pref;
	jmin = min(0LL, pref);

	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		pref = pref + x;
		ans = max(ans, pref - jmin);
		if (pref < jmin) {
			jmin = pref;
		}
	}

	cout << ans << '\n';
	return 0;
}
