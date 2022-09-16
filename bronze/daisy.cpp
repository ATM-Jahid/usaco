#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> jar(n);
	for (auto &el : jar) cin >> el;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int dx = 0, cum = 0;
		for (int j = i; j < n; j++) {
			dx++;
			cum += jar[j];
			if (cum % dx == 0) {
				int avg = cum / dx;
				for (int k = i; k <= j; k++) {
					if (jar[k] == avg) {
						ans++;
						break;
					}
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
