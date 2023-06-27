#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);

	int N; cin >> N;
	string jar; cin >> jar;

	for (int k = 0; k < N; k++) {
		int count = 0;
		set<string> collect;
		for (int i = 0; i+k < N; i++) {
			count++;
			string s;
			s += jar.substr(i, k+1);
			collect.insert(s);
		}
		if (count == collect.size()) {
			cout << k+1 << '\n';
			return 0;
		}
	}

	return 0;
}
