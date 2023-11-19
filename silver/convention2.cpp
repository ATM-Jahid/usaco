#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("convention2.in");
	ofstream fout("convention2.out");

	int n; fin >> n;
	vector<vector<int>> logs; // (arrival, seniority, time)
	for (int i = 0; i < n; i++) {
		int a, t; fin >> a >> t;
		logs.push_back({a, i, t});
	}
	sort(begin(logs), end(logs));

	set<vector<int>> qset; // (seniority, arrival, time)
	int elapsed = 0, max_wait = 0;
	for (auto &l : logs) {
		if (l[0] <= elapsed) {
			qset.insert({l[1], l[0], l[2]});
		} else {
			bool sw = true;
			while (l[0] > elapsed) {
				if (qset.empty()) {
					sw = false;
					elapsed = l[0] + l[2];
					break;
				} else {
					auto it = begin(qset);
					max_wait = max(max_wait, elapsed - (*it)[1]);
					elapsed += (*it)[2];
					qset.erase(it);
				}
			}
			if (sw) {
				qset.insert({l[1], l[0], l[2]});
			}
		}
	}
	for (auto &q : qset) {
		max_wait = max(max_wait, elapsed - q[1]);
		elapsed += q[2];
	}
	fout << max_wait << endl;

	return 0;
}
