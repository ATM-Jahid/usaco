#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("helpcross.in");
	ofstream fout("helpcross.out");

	int c, n; fin >> c >> n;
	vector<int> t(c);
	vector<pair<int, int>> ab(n);
	for (auto &x : t) fin >> x;
	for (auto &[a, b] : ab) fin >> a >> b;

	sort(begin(t), end(t));
	sort(begin(ab), end(ab), [](auto &l, auto &r) {
		if (l.second == r.second) return l.first < r.first;
		else return l.second < r.second;
	});

	int pairs = 0;
	vector<int> used_t(c);
	for (auto &[a, b] : ab) {
		int l = distance(begin(t), lower_bound(begin(t), end(t), a));
		int r = distance(begin(t), upper_bound(begin(t), end(t), b));
		for (int i = l; i < r; i++) {
			if (!used_t[i]) {
				pairs++;
				used_t[i] = 1;
				break;
			}
		}
	}

	fout << pairs << endl;
	return 0;
}
