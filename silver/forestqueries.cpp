#include <bits/stdc++.h>
using namespace std;

int forest[1001][1001];

int main() {
	int n, q; cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			forest[i][j] = forest[i-1][j] + forest[i][j-1] - forest[i-1][j-1];
			char c; cin >> c;
			if (c == '*') forest[i][j]++;
		}
	}

	for (int i = 0; i < q; i++) {
		int i1, j1, i2, j2;
		cin >> i1 >> j1 >> i2 >> j2;
		cout << forest[i2][j2] - forest[i1-1][j2]
			- forest[i2][j1-1] + forest[i1-1][j1-1] << '\n';
	}

	return 0;
}
