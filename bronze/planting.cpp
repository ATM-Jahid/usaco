#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream cin("planting.in");
	ofstream cout("planting.out");
	
	int N; cin >> N;
	vector<int> adj[N];
	for (int i = 0; i < N-1; i++) {
		int a, b; cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, int(adj[i].size()));
	}
	cout << ans+1 << '\n';

	return 0;
}
