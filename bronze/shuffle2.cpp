#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);

	int n; cin >> n;
	vector<int> shuf(n), order(n), old_order(n);
	for (auto &el : shuf) {
		cin >> el;
		el--;
	}
	for (auto &el : order) cin >> el;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			old_order[j] = order[shuf[j]];
		}
		order = old_order;
	}

	for (auto &el : order) cout << el << '\n';
	return 0;
}
