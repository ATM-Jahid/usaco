#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> x(n), y(n);
	for (auto &el : x) cin >> el;
	for (auto &el : y) cin >> el;

	int most = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			most = max(most,
				int(pow(x[j]-x[i], 2) + pow(y[j]-y[i], 2)));
		}
	}

	cout << most << '\n';
	return 0;
}
