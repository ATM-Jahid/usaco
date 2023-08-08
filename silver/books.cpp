#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t; cin >> n >> t;
	vector<int> jar(n);
	for (auto &x : jar) cin >> x;

	int sum = 0, best = 0;
	int left, right = 0;
	for (left = 0; left < n; left++) {
		while (right < n && sum + jar[right] <= t) {
			sum += jar[right];
			right++;
		}
		best = max(best, right - left);
		sum -= jar[left];
	}
	cout << best << endl;

	return 0;
}
