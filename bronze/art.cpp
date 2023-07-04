#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);

	int N; cin >> N;
	vector<vector<int>> jar(N, vector<int>(N)), bounds(10, vector<int>(4));
	for (int k = 1; k < 10; k++) {
		bounds[k][0] = N+1; bounds[k][1] = -1;
		bounds[k][2] = N+1; bounds[k][3] = -1;
	}

	vector<int> vis(10), rej(10);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c; cin >> c;
			int k = int(c-'0');
			jar[i][j] = k;
			vis[k]++;
			bounds[k][0] = min(bounds[k][0], i);
			bounds[k][1] = max(bounds[k][1], i);
			bounds[k][2] = min(bounds[k][2], j);
			bounds[k][3] = max(bounds[k][3], j);
		}
	}

	for (int k = 1; k < 10; k++) {
		if (vis[k] > 0) {
			for (int i = bounds[k][0]; i <= bounds[k][1]; i++) {
				for (int j = bounds[k][2]; j <= bounds[k][3]; j++) {
					if (jar[i][j] != k) {
						rej[jar[i][j]]++;
					}
				}
			}
		}
	}

	int ans = 0;
	for (int k = 1; k < 10; k++) {
		if (vis[k] > 0 && rej[k] == 0) {
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}
