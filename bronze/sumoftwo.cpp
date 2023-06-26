#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, sum; cin >> n >> sum;
	set<int> jar;
	map<int, vector<int>> places;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		jar.insert(t);
		places[t].push_back(i+1);
	}

	int found = 0;
	for (auto &x : jar) {
		if (x == sum-x && places[x].size() > 1) {
			cout << places[x][0] << ' ' << places[x][1] << '\n';
			found = 1;
			break;
		} else if (x != sum-x && jar.count(sum-x)) {
			cout << places[x][0] << ' ' << places[sum-x][0] << '\n';
			found = 1;
			break;
		}
	}

	if(!found) cout << "IMPOSSIBLE\n";
	return 0;
}
