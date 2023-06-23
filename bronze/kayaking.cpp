#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> weights(2*n);
	for (auto &x : weights) cin >> x;
	sort(begin(weights), end(weights));

	vector<int> oddcum(2*n), evencum(2*n);
	int sum = 0;
	for (int i = 1; i < 2*n; i+=2) {
		sum += weights[i] - weights[i-1];
		oddcum[i] = sum;
		if (i < 2*n-1) oddcum[i+1] = sum;
	}
	sum = 0;
	for (int i = 2; i < 2*n; i+=2) {
		sum += weights[i] - weights[i-1];
		evencum[i] = sum;
		evencum[i+1] = sum;
	}

	int res = INT_MAX;
	for (int i = 0; i < 2*n; i+=2) {
		for (int j = i+1; j < 2*n; j+=2) {
			int imb = 0;

			// before the first single kayak
			if (i) {
				imb += oddcum[i-1];
			}
			// in between the two single kayaks
			if (j != i+1) {
				imb += evencum[j-1] - evencum[i];
			}
			// after the second single kayak
			if (j < 2*n-1) {
				imb += oddcum[2*n-1] - oddcum[j];
			}

			res = min(res, imb);
		}
	}

	cout << res << '\n';
	return 0;
}
