#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream cin("factory.in");
	ofstream cout("factory.out");

	int N; cin >> N;
	vector<int> adj[N+1];
	for (int i = 0; i < N-1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}

	int zeros = 0, zind;
	for (int i = 1; i <= N; i++) {
		if (adj[i].size() == 0) {
			zeros++;
			zind = i;
		}
	}

	if (zeros == 1) cout << zind << '\n';
	else cout << "-1\n";

	return 0;
}
