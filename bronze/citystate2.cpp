#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);

	int N; cin >> N;
	set<string> states;
	map<string, vector<string>> cities_in_states;
	for (int i = 0; i < N; i++) {
		string city, state;
		cin >> city >> state;
		states.insert(state);
		cities_in_states[state].push_back(city);
	}

	int cnt = 0;
	for (auto it1 = begin(states); it1 != end(states); it1 = next(it1)) {
		for (auto it2 = next(it1); it2 != end(states); it2 = next(it2)) {
			int c1 = 0;
			for (auto &x : cities_in_states[*it1]) {
				if (x.substr(0, 2) == *it2) {
					c1++;
				}
			}
			int c2 = 0;
			for (auto &y : cities_in_states[*it2]) {
				if (y.substr(0, 2) == *it1) {
					c2++;
				}
			}
			cnt += c1 * c2;
		}
	}

	cout << cnt << '\n';
	return 0;
}
