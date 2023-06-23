#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

	int N; cin >> N;
	vector<int> pos(N);
	for (auto &x : pos) cin >> x;
	sort(begin(pos), end(pos));

	int res = 0;
	for (int i = 0; i < N; i++) {
		int count = 1;

		// forward
		int Ri = i;
		for (int t = 1;; t++) {
			int Rcount = 0, Roff = 1, j;
			for (j = Ri+1; j < N; j++) {
				if (pos[j] <= pos[Ri] + t) {
					Rcount++;
				} else {
					break;
				}
			}
			count += Rcount;
			if (Rcount && j != N) {
				Roff = 0;
				Ri = j-1;
			}
			if (Roff) break;
		}

		// backward
		int Li = i;
		for (int t = 1;; t++) {
			int Lcount = 0, Loff = 1, j;
			for (j = Li-1; j > -1; j--) {
				if (pos[j] >= pos[Li] - t) {
					Lcount++;
				} else {
					break;
				}
			}
			count += Lcount;
			if (Lcount && j != -1) {
				Loff = 0;
				Li = j+1;
			}
			if (Loff) break;
		}

		res = max(res, count);
	}

	cout << res << '\n';
	return 0;
}
