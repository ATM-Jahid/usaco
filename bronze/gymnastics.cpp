#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

	int K, N; cin >> K >> N;
	map<int, int> pos;
	map<pair<int, int>, set<int>> sto;
	for (int k = 0; k < K; k++) {
		for (int n = 0; n < N; n++) {
			int tmp; cin >> tmp;
			pos[tmp] = n;
		}
		for (int i = 1; i < N; i++) {
			for (int j = i+1; j < N+1; j++) {
				pair<int, int> p (i, j);
				if (pos[i] > pos[j]) sto[p].insert(0);
				else sto[p].insert(1);
			}
		}
	}

	int ans = 0;
	for (auto el : sto) {
		if (el.second.size() == 1) ans++;
	}

	cout << ans << '\n';
	return 0;
}
