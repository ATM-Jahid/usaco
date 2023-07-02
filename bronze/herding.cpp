#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);

	vector<int> pos(3);
	for (auto &x : pos) cin >> x;
	sort(begin(pos), end(pos));

	int a = pos[2] - pos[1], b = pos[1] - pos[0];
	int pmax = (a > b) ? a-1 : b-1;
	int pmin = (a < b) ? a-1 : b-1;

	// handle all pmin edge cases
	if (pmax == 0) {
		cout << 0 << '\n';
	} else if (pmin == 0 && pmax == 1) {
		cout << 1 << '\n';
	} else if (pmin == 0 && pmax > 1) {
		cout << 2 << '\n';
	} else if (pmin == 1) {
		cout << 1 << '\n';
	} else if (pmin > 1) {
		cout << 2 << '\n';
	}

	// handle all pmax cases
	cout << pmax << '\n';

	return 0;
}
