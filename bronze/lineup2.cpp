#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);

	vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice",
							"Bella", "Blue", "Betsy", "Sue"};
	sort(begin(cows), end(cows));
	map<string, int> ind;
	for (int i = 0; i < 8; i++) ind[cows[i]] = i;

	int n; cin >> n;
	vector<int> adj[8];
	for (int i = 0; i < n; i++) {
		string cow1, tmp, cow2;
		cin >> cow1;
		for (int j = 0; j < 4; j++) cin >> tmp;
		cin >> cow2;
		adj[ind[cow1]].push_back(ind[cow2]);
		adj[ind[cow2]].push_back(ind[cow1]);
	}

	vector<int> line, used(8);
	for (int i = 0; i < 8; i++) {
		if (!used[i] && adj[i].size() <= 1) {
			used[i] = 1;
			line.push_back(i);

			if (adj[i].size() == 1) {
				used[adj[i][0]] = 1;
				line.push_back(adj[i][0]);

				int curr = adj[i][0];
				while (adj[curr].size() == 2) {
					int f = adj[curr][0], s = adj[curr][1];
					int next = (used[f] ? s : f);
					used[next] = 1;
					line.push_back(next);
					curr = next;
				}
			}
		}
	}

	for (auto &x : line) cout << cows[x] << endl;

	return 0;
}
