#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream cin("revegetate.in");
	ofstream cout("revegetate.out");

	int N, M; cin >> N >> M;
	vector<int> adj[N+1];
	for (int m = 0; m < M; m++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> color(N+1);
	for (int i = 1; i <= N; i++) {
		set<int> colsAdj;
		for (auto &x : adj[i]) {
			if (color[x] > 0) colsAdj.insert(color[x]);
		}
		for (int c = 1; c < 5; c++) {
			if (!colsAdj.count(c)) {
				color[i] = c;
				break;
			}
		}
		cout << color[i];
	}
	cout << endl;

	return 0;
}
