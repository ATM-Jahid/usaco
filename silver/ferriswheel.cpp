#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x; cin >> n >> x;
	vector<int> weights(n);
	for (auto &w : weights) cin >> w;
	sort(begin(weights), end(weights));

	int l = 0, r = n-1, gondolas = 0;
	while (l < r) {
		gondolas++;
		if (weights[l] + weights[r] <= x) l++;
		r--;
	}

	if (l == r) gondolas++;
	cout << gondolas << endl;
	return 0;
}
