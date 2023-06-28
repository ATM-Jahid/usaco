#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);

	int N; cin >> N;
	map<string, vector<string>> cities_in_states;
	for (int i = 0; i < N; i++) {
		string city, state;
		cin >> city >> state;
		cities_in_states[state].push_back(city);
	}

	int cnt = 0;
	for (auto &st1 : cities_in_states) {
		for (auto &ci1 : st1.second) {
			string st2 = ci1.substr(0, 2);
			if (st1.first != st2 && cities_in_states.count(st2)) {
				for (auto &ci2 : cities_in_states[st2]) {
					if (ci2.substr(0, 2) == st1.first) {
						cnt++;
					}
				}
			}
		}
	}

	cout << cnt/2 << '\n';
	return 0;
}
