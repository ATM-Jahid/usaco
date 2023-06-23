#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cowqueue.in", "r", stdin);
	freopen("cowqueue.out", "w", stdout);

	int N; cin >> N;
	vector<pair<int, int>> cows(N);
	for (auto &x : cows) {
		cin >> x.first >> x.second;
	}
	sort(begin(cows), end(cows));

	vector<int> endtimes(N);
	endtimes[0] = cows[0].first + cows[0].second;
	for (int i = 1; i < N; i++) {
		if (cows[i].first > endtimes[i-1]) {
			endtimes[i] = cows[i].first + cows[i].second;
		} else {
			endtimes[i] = endtimes[i-1] + cows[i].second;
		}
	}

	cout << endtimes[N-1] << '\n';
	return 0;
}
