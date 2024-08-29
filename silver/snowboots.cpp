#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("snowboots.in");
	ofstream fout("snowboots.out");

	int n, b; fin >> n >> b;
	vector<pair<int, int>> jar(n);
	for (int i = 0; i < n; i++) {
		jar[i].first = i;
		fin >> jar[i].second;
	}

	jar.erase(begin(jar)); jar.erase(end(jar)-1);
	sort(begin(jar), end(jar), [](auto &l, auto &r) {
		return l.second < r.second;
	});

	int occ[100005];
	priority_queue<int> most;
	occ[n-1]++; most.push(n-1);

	set<int> pins;
	pins.insert(0); pins.insert(n-1);

	map<int, int> pam;
	pam[0] = n-1;

	for (auto &el : jar) {
		int p = el.first, s = el.second;
		auto it = pins.lower_bound(p);
		int l = *prev(it), r = *it;

		pins.insert(p);
		occ[r-l]--;
		occ[p-l]++; most.push(p-l);
		occ[r-p]++; most.push(r-p);

		while (!occ[most.top()]) most.pop();
		pam[s] = most.top();
	}

	vector<int> heights;
	for (auto &el : jar) heights.push_back(el.second);

	for (int i = 0; i < b; i++) {
		int s, d; fin >> s >> d;
		auto it = upper_bound(begin(heights), end(heights), s);

		int need = pam[*prev(it)];
		if (d < need) fout << "0\n";
		else fout << "1\n";
	}

	return 0;
}
