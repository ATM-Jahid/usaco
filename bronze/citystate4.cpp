#include <bits/stdc++.h>
using namespace std;

int index(string s) {
	int ind = 0;
	for (char &c : s) {
		ind = 26 * ind + (c - 'A');
	}
	return ind;
}

int main() {
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);

	int N; cin >> N;
	vector<pair<string, string>> cists;
	for (int i = 0; i < N; i++) {
		string city, state;
		cin >> city >> state;
		cists.push_back({city.substr(0,2), state});
	}

	int cnt = 0;
	vector<int> seen(26 * 26 * 26 * 26);
	for (const auto &[c, s] : cists) {
		if (c != s) {
			cnt += seen[index(s + c)];
		}
		seen[index(c + s)]++;
	}

	cout << cnt << '\n';
	return 0;
}
