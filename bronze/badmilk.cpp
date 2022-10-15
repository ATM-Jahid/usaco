#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
	ifstream fin("badmilk.in");
	ofstream fout("badmilk.out");

	int N, M, D, S; fin >> N >> M >> D >> S;
	vector<set<pii>> jar(N+1);
	vector<pii> sick(S);
	vector<int> milk(M+1);

	for (int i = 0; i < D; i++) {
		int p, m, t; fin >> p >> m >> t;
		jar[p].insert({m, t});
	}
	for (int i = 0; i < S; i++) {
		int p, t; fin >> p >> t;
		sick[i] = {p, t};
	}

	for (int i = 0; i < S; i++) {
		set<int> un;
		int p = sick[i].first, s = sick[i].second;
		for (auto el : jar[p]) {
			int m = el.first, t = el.second;
			if (t < s) {
				un.insert(m);
			}
		}
		for (auto el : un) milk[el]++;
	}

	int res = 0;
	for (int m = 1; m < M+1; m++) {
		if (milk[m] == S) {
			int run = 0;
			for (int j = 1; j < N+1; j++) {
				for (auto el : jar[j]) {
					if (el.first == m) {
						run++;
						break;
					}
				}
			}
			res = max(res, run);
		}
	}

	fout << res << '\n';
	return 0;
}
