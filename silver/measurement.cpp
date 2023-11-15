#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("measurement.in");
	ofstream fout("measurement.out");

	int n, g; fin >> n >> g;
	vector<vector<int>> logs;
	for (int i = 0; i < n; i++) {
		int day, id, upd; fin >> day >> id >> upd;
		logs.push_back({day, id, upd});
	}
	sort(begin(logs), end(logs));

	map<int, int> milk; // <id, output>
	set<pair<int, int>> full; // <output, id>
	full.insert({g, 0}); // zeroth cow always at G
	set<int> prev;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int id = logs[i][1], upd = logs[i][2];

		if (!milk.count(id)) {
			milk[id] = g;
		} else {
			full.erase({milk[id], id});
		}
		milk[id] += upd;
		full.insert({milk[id], id});

		set<int> curr;
		int most = full.rbegin()->first;
		for (auto rit = full.rbegin(); rit != full.rend(); rit++) {
			if (rit->first == most) {
				curr.insert(rit->second);
			} else {
				break;
			}
		}

		if (curr != prev) ans++;
		prev = curr;
	}
	fout << ans << endl;

	return 0;
}
