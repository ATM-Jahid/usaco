#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	int N, M; cin >> N >> M;
	vector<string> spotty(N), clean(N);
	for (auto &el : spotty) cin >> el;
	for (auto &el : clean) cin >> el;

	int pos = 0;
	for (int m = 0; m < M; m++) {
		int sp = 0;
		for (auto el : spotty) {
			if (el[m] == 'A') sp |= 1;
			else if (el[m] == 'C') sp |= 2;
			else if (el[m] == 'G') sp |= 4;
			else if (el[m] == 'T') sp |= 8;
			else return -1;
		}
		int cl = 0;
		for (auto el : clean) {
			if (el[m] == 'A') cl |= 1;
			else if (el[m] == 'C') cl |= 2;
			else if (el[m] == 'G') cl |= 4;
			else if (el[m] == 'T') cl |= 8;
			else return -1;
		}
		if (!(sp & cl)) pos++;
	}

	cout << pos << '\n';
	return 0;
}
