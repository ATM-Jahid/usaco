#include <bits/stdc++.h>
using namespace std;

int ans[1501][26];

int main() {
	int n; cin >> n;
	string jar; cin >> jar;

	for (int i = 1; i <= n; i++) {
		for (char c = 'a'; c <= 'z'; c++) {
			int r = -1, best = 0, ext = i;
			for (int l = 0; l < n; l++) {
				while (r+1 < n && (jar[r+1] == c || ext)) {
					r++;
					if (jar[r] != c) ext--;
				}
				best = max(best, r-l+1);
				if (jar[l] != c) ext++;
			}
			ans[i][int(c-'a')] = best;
		}
	}

	int q; cin >> q;
	while (q--) {
		int m; cin >> m;
		char c; cin >> c;
		cout << ans[m][int(c-'a')] << '\n';
	}

	return 0;
}
