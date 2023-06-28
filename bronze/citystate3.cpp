#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);

	int N; cin >> N;
	set<string> states;
	map<string, int> combinations;
	for (int i = 0; i < N; i++) {
		string city, state;
		cin >> city >> state;
		states.insert(state);
		combinations[city.substr(0,2)+state]++;
	}

	int cnt = 0;
	for (auto it1 = begin(states); it1 != end(states); it1 = next(it1)) {
		for (auto it2 = next(it1); it2 != end(states); it2 = next(it2)) {
			string cmb1 = *it1 + *it2, cmb2 = *it2 + *it1;
			cnt += combinations[cmb1] * combinations[cmb2];
		}
	}

	cout << cnt << '\n';
	return 0;
}
