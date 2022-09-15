#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);

	int x, y, m;
	cin >> x >> y >> m;

	int amt = -1;
	for (int i = 0; y * i <= m; i++) {
		int res = (m - y*i) % x;
		amt = max(amt, m - res);
		if (amt == m) break;
	}

	cout << amt << '\n';
	return 0;
}
