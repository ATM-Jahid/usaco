#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);

	int n; cin >> n;
	vector<int> line(n), id(n);
	for (auto &el : line) cin >> el;
	for (auto &el : id) cin >> el;

	int err;
	for (int i = 0; i < n; i++) {
		if (line[i] != i+1) {
			err = i;
			break;
		}
	}

	for (int i = 3; i > 0; i--) {
		swap(id[err+i], id[err+i-1]);
	}

	for (auto &el : id) cout << el << '\n';
	return 0;
}
