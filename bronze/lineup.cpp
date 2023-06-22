#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);

	int n; cin >> n;
	vector<pair<string, string>> conds;
	for (int i = 0; i < n; i++) {
		string cow1, tmp, cow2;
		cin >> cow1;
		for (int j = 0; j < 4; j++) cin >> tmp;
		cin >> cow2;
		conds.push_back({cow1, cow2});
	}

	vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice",
							"Bella", "Blue", "Betsy", "Sue"};
	sort(begin(cows), end(cows));

	do {
		bool valid = true;
		for (auto &c: conds) {
			auto a = find(begin(cows), end(cows), c.first);
			auto b = find(begin(cows), end(cows), c.second);
			if (abs(a-b) > 1) {
				valid = false;
			}
		}
		if (valid) {
			break;
		}
	} while(next_permutation(begin(cows), end(cows)));

	for (auto &x : cows) cout << x << endl;
	return 0;
}
