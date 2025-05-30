#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("angry.in");
	ofstream fout("angry.out");

	int n; fin >> n;
	vector<int> x(n);
	for (auto &el : x) fin >> el;
	sort(begin(x), end(x));

	if (n == 2) {
		fout << fixed << setprecision(1) << (x[1]-x[0])/2.0 << endl;
		return 0;
	}

	double best = 1e9;
	int l = 0, r = n-1, P_l = 0, P_r = 0, pos;

	while (l < r) {
		double val = max(max(P_l, P_r) + 1.0, (x[r] - x[l]) / 2.0);
		best = min(best, val);

		int cand_l = max(P_l + 1, x[l+1] - x[l]);
		int cand_r = max(P_r + 1, x[r] - x[r-1]);

		if (cand_l < cand_r) {
			pos = l;
			while (pos+1 < n && x[pos+1] - x[l] <= cand_l) pos++;
			l = pos;
			P_l = cand_l;
		} else {
			pos = r;
			while (pos-1 >= 0 && x[r] - x[pos-1] <= cand_r) pos--;
			r = pos;
			P_r = cand_r;
		}
	}

	fout << fixed << setprecision(1) << best << endl;

	return 0;
}
