#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, n; cin >> k >> n;
	vector<int> jury(k), scores(n);
	for (auto &x : jury) cin >> x;
	for (auto &x : scores) cin >> x;
	sort(begin(scores), end(scores));

	int sum = 0;
	vector<int> cum;
	for (int i = 0; i < k; i++) {
		sum += jury[i];
		cum.push_back(sum);
	}
	sort(begin(cum), end(cum));
	auto it = unique(begin(cum), end(cum));
	cum.resize(distance(begin(cum), it));

	k = cum.size();
	int cnt = 0;
	if (k >= n) {
		for (int s = 0; s <= k-n; s++) {
			int empties = 0, valid = 1;
			int d = scores[0] - cum[s];
			for (int i = 1; i < n; i++) {
				if (scores[i] - cum[s+i+empties] == d) continue;
				else if (empties < k-n-s) {
					empties++;
					i--;
				}
				else {
					valid = 0;
					break;
				}
			}
			if (valid) cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}
