#include <bits/stdc++.h>
using namespace std;

int to_num(char c) {
	if (c == 'A') return 0;
	else if (c == 'C') return 1;
	else if (c == 'G') return 2;
	else if (c == 'T') return 3;
	else return -1;
}

int main() {
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	int N, M; cin >> N >> M;
	vector<string> spotty(N), clean(N);
	for (auto &el : spotty) cin >> el;
	for (auto &el : clean) cin >> el;

	int tri = 0;
	for (int i = 0; i < M; i++) {
		for (int j = i+1; j < M; j++) {
			for (int k = j+1; k < M; k++) {
				int dup = 0;
				vector<int> chk(64);
				for (auto el : spotty) {
					int s = 16 * to_num(el[i])
						+ 4 * to_num(el[j])
						+ to_num(el[k]);
					chk[s] = 1;
				}
				for (auto el : clean) {
					int s = 16 * to_num(el[i])
						+ 4 * to_num(el[j])
						+ to_num(el[k]);
					if (chk[s]) {
						dup = 1;
						break;
					}
				}
				if (!dup) tri++;
			}
		}
	}

	cout << tri << '\n';
	return 0;
}
