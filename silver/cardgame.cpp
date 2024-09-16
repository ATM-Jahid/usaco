#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("cardgame.in");
	ofstream fout("cardgame.out");

	int n; fin >> n;
	vector<bool> elsie(2*n+1);
	vector<int> elsie_hi, elsie_lo;
	for (int i = 0; i < n; i++) {
		int t; fin >> t;
		elsie[t] = 1;
		if (i < n/2) elsie_hi.push_back(t);
		else elsie_lo.push_back(t);
	}
	sort(begin(elsie_hi), end(elsie_hi));
	sort(begin(elsie_lo), end(elsie_lo));

	int nlo = 0;
	vector<int> bessie_hi, bessie_lo;
	for (int i = 1; i <= 2*n; i++) {
		if (!elsie[i]) {
			if (nlo < n/2) {
				bessie_lo.push_back(i);
				nlo++;
			} else {
				bessie_hi.push_back(i);
			}
		}
	}

	int wins = 0, ib = 0, ie = 0;
	while (ib < n/2 && ie < n/2) {
		if (bessie_hi[ib] > elsie_hi[ie]) {
			wins++;
			ib++;
			ie++;
		} else {
			ib++;
		}
	}

	ib = n/2 - 1; ie = n/2 - 1;
	while (ib >= 0 && ie >= 0) {
		if (bessie_lo[ib] < elsie_lo[ie]) {
			wins++;
			ib--;
			ie--;
		} else {
			ib--;
		}
	}

	fout << wins << endl;
	return 0;
}
