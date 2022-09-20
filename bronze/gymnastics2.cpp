#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

	int K, N; cin >> K >> N;
	set<pair<int, int>> seen;

	for (int k = 0; k < K; k++) {
		vector<int> stage(N);
		for (auto &el : stage) cin >> el;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				seen.insert({stage[i], stage[j]});
			}
		}
	}

	cout << N * (N-1) - seen.size() << '\n';
	return 0;
}
