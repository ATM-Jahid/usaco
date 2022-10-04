#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);

	int n; cin >> n;
	vector<int> st(n), en(n), jar(1000);

	int cum = 0;
	for (int i = 0; i < n; i++) {
		cin >> st[i] >> en[i];
		for (int j = st[i]; j < en[i]; j++) {
			jar[j]++;
			if (jar[j] == 1) cum++;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int red = 0;
		for (int j = st[i]; j < en[i]; j++) {
			if (jar[j] == 1) red++;
		}
		ans = max(ans, cum - red);
	}

	cout << ans << '\n';
	return 0;
}
