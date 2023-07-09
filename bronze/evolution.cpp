#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("evolution.in");
	ofstream fout("evolution.out");

	int N; fin >> N;
	vector<string> data[N];
	map<string, int> freqMap;
	for (int i = 0; i < N; i++) {
		int K; fin >> K;
		for (int j = 0; j < K; j++) {
			string t; fin >> t;
			data[i].push_back(t);
			freqMap[t]++;
		}
	}

	map<string, set<string>> tree;
	for (int i = 0; i < N; i++) {
		if (data[i].size() > 1) {
			vector<pair<int, string>> lorder;
			for (int j = 0; j < data[i].size(); j++) {
				lorder.push_back({freqMap[data[i][j]], data[i][j]});
			}
			sort(begin(lorder), end(lorder));
			for (int k = 0; k < lorder.size()-1; k++) {
				tree[lorder[k].second].insert(lorder[k+1].second);
			}
		}
	}

	for (auto &x : tree) {
		fout << x.first << " -> ";
		for (auto &y : x.second) {
			fout << y << ' ';
		}
		fout << endl;
	}
	fout << endl;

	for (auto &x : tree) {
		if (x.second.size() > 1) {
			fout << "no\n";
			return 0;
		}
	}

	for (int i = 0; i < N; i++) {
		vector<pair<int, string>> lorder;
		for (int j = 0; j < data[i].size(); j++) {
			lorder.push_back({freqMap[data[i][j]], data[i][j]});
		}
		if (lorder.size() == 0) {
		} else if (lorder.size() == 1) {
			if (tree[lorder[0].second].size()) {
				fout << "no\n";
				return 0;
			}
		} else if (lorder.size() > 1) {
			sort(begin(lorder), end(lorder));
			int k;
			for (k = 0; k < lorder.size()-1; k++) {
				if (*begin(tree[lorder[k].second]) != lorder[k+1].second) {
					fout << "no\n";
					return 0;
				}
			}
			if (tree[lorder[k].second].size()) {
				fout << "no\n";
				return 0;
			}
		}
	}

	fout << "yes\n";
	return 0;
}
