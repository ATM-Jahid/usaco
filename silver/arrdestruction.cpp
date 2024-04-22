#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n; cin >> n;
	multiset<int> a;
	for (int i = 0; i < 2*n; i++) {
		int tmp; cin >> tmp;
		a.insert(tmp);
	}
	vector<int> jar(begin(a), end(a));

	for (int i = 0; i < 2*n-1; i++) {
		int X = jar[2*n-1];

		multiset<int> aa = a;
		aa.erase(aa.find(jar[i]));
		aa.erase(aa.find(X));

		string res = "";
		res += to_string(jar[i] + X) + '\n';
		res += to_string(jar[i]) + ' ' + to_string(X) + '\n';

		for (int r = 2*n-2; r >= 0; r--) {
			int R = jar[r];
			if (aa.find(R) == end(aa)) continue;
			aa.erase(aa.find(R));

			int L = X - R;
			if (aa.find(L) == end(aa)) {
				break;
			} else {
				aa.erase(aa.find(L));
				res += to_string(L) + ' ' + to_string(R) + '\n';
				X = R;
			}
		}

		if (!aa.size()) {
			cout << "YES\n";
			cout << res;
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
