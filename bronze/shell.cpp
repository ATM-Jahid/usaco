#include <bits/stdc++.h>
using namespace std;

int check(int place, int n, vector<int> &jar) {
	int rig = 0;

	for (int i = 0; i < n; i++) {
		if (place == jar[3*i]) place = jar[3*i+1];
		else if (place == jar[3*i+1]) place = jar[3*i];
		if (place == jar[3*i+2]) rig++;
	}

	return rig;
}

int main() {
	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);

	int n; cin >> n;
	vector<int> jar(3*n);
	for (auto &el : jar) cin >> el;

	int ans = 0;
	ans = max(ans, check(1, n, jar));
	ans = max(ans, check(2, n, jar));
	ans = max(ans, check(3, n, jar));

	cout << ans << '\n';
	return 0;
}
