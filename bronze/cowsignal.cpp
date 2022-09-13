#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);

	int m, n, k;
	cin >> m >> n >> k;
	vector<char> pic(m*n);
	for (auto &el : pic) cin >> el;

	string rans = "";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			rans += string(k, pic[i*n+j]);
		}
		rans += '\n';
		for (int p = 0; p < k; p++) cout << rans;
		rans = "";
	}

	return 0;
}
