#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<int> jar(n+1);
	map<int, int> cnt;
	cnt[0] = 1;

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		jar[i] = jar[i-1] + a;
		jar[i] = (jar[i] % n + n) % n;
		ans += 1LL * cnt[jar[i]];
		cnt[jar[i]]++;
	}

	cout << ans << '\n';
	return 0;
}
