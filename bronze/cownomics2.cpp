#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	int N, M; cin >> N >> M;
	vector<string> spotty(N), clean(N);
	for (auto &el : spotty) cin >> el;
	for (auto &el : clean) cin >> el;

	int tri = 0;
	for (int i = 0; i < M; i++) {
		for (int j = i+1; j < M; j++) {
			for (int k = j+1; k < M; k++) {
				int dup = 0;
				set<string> sp;
				for (auto el : spotty) {
					string s = string() + el[i] + el[j] + el[k];
					sp.insert(s);
				}
				for (auto el : clean) {
					string s = string() + el[i] + el[j] + el[k];
					if (sp.count(s)) {
						dup = 1;
						break;
					}
				}
				if (!dup) tri++;
			}
		}
	}

	cout << tri << '\n';
	return 0;
}
