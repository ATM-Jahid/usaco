#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("sort.in");
	ofstream fout("sort.out");

	int n; fin >> n;
	vector<int> jar(n), ind(n);
	for (auto &x : jar) fin >> x;

	iota(begin(ind), end(ind), 0);
	stable_sort(begin(ind), end(ind), [&](auto &l, auto &r) {
		return jar[l] < jar[r];
	});

	for (int i = 0; i < n; i++) ind[i] -= i;
	fout << *max_element(begin(ind), end(ind)) + 1 << endl;

	return 0;
}
