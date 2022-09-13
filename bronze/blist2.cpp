#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);

	int n; cin >> n;
	vector<int> jar(1001);

	int start, end, amt;
	for (int i = 0; i < n; i++) {
		cin >> start >> end >> amt;
		jar[start] += amt;
		jar[end] -= amt;
	}

	int ans = 0, cum = 0;
	for (auto &el : jar) {
		cum += el;
		ans = max(ans, cum);
	}

	cout << ans << '\n';
	return 0;
}
