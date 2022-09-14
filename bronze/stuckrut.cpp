#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<char> dir(n);
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> dir[i] >> x[i] >> y[i];
	}

	for (int i = 0; i < n; i++) {
		int cut = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (dir[j] != dir[i]) {
				if (dir[j] == 'E' && y[j] > y[i] && x[j] < x[i]
						&& (y[j]-y[i]) > (x[i]-x[j])) {
					cut = min(cut, y[j] - y[i]);
				} else if (dir[j] == 'N' && x[j] > x[i] && y[j] < y[i]
						&& (x[j]-x[i]) > (y[i]-y[j])) {
					cut = min(cut, x[j] - x[i]);
				}
			}
		}
		if (cut == INT_MAX) cout << "Infinity\n";
		else cout << cut << '\n';
	}

	return 0;
}
