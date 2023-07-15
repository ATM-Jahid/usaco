#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, x; cin >> n >> x;
	vector<ll> jar(n+1);
	map<ll, int> cnt;
	cnt[0] = 1;

	ll needed, ans = 0;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		jar[i] = jar[i-1] + a;
		needed = jar[i] - x;
		ans += cnt[needed];
		cnt[jar[i]]++;
	}

	cout << ans << '\n';
	return 0;
}
