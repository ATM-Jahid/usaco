#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, x; cin >> n >> x;
	vector<ll> jar(n+1);
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		jar[i] = jar[i-1] + a;
	}

	int ans = 0, p1, p2 = 1;
	for (p1 = 0; p1 < n && p2 <= n; p1++) {
		if (jar[p2] - jar[p1] == x) {
			ans++;
		} else if (jar[p2] - jar[p1] < x) {
			p1--;
			p2++;
		}
	}

	cout << ans << '\n';
	return 0;
}
