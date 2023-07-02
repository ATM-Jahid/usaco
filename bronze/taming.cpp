#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);

	int N; cin >> N;
	vector<int> log(N), rec(N);
	for (auto &x : log) cin >> x;

	for (int rp = N-1; rp >= 0; rp--) {
		if (log[rp] != -1) {
			int t = 0;
			for (; t <= log[rp] && t <= rp; t++) {
				rec[rp-t] = log[rp] - t;
			}
			rp -= t-1;
		} else {
			rec[rp] = -1;
		}
	}

	if (rec[0] != 0 && rec[0] != -1) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 1; i < N; i++) {
		if (log[i] != rec[i] && log[i] != -1) {
			cout << "-1\n";
			return 0;
		}
	}

	rec[0] = 0;
	int nyes = 0, nmaybe = 0;
	for (auto &x : rec) {
		if (x == 0) nyes++;
		if (x == -1) nmaybe++;
	}
	cout << nyes << ' ' << nyes+nmaybe << '\n';

	return 0;
}
