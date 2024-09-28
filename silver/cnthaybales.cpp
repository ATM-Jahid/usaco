#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("haybales.in");
	ofstream fout("haybales.out");

	int n, q; fin >> n >> q;
	vector<int> haybales(n);
	for (auto &x : haybales) fin >> x;
	sort(begin(haybales), end(haybales));

	for (int i = 0; i < q; i++) {
		int l, r; fin >> l >> r;
		auto lit = lower_bound(begin(haybales), end(haybales), l),
			 rit = upper_bound(begin(haybales), end(haybales), r);
		fout << distance(lit, rit) << endl;
	}

	return 0;
}
