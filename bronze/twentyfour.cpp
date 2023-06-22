#include <bits/stdc++.h>
using namespace std;

int calc(int mode, int op1, int op2) {
	if (mode == 0) {
		return op1 + op2;
	} else if (mode == 1) {
		return op1 - op2;
	} else if (mode == 2) {
		return op1 * op2;
	} else if (mode == 3 && op2 != 0 && op1 % op2 == 0) {
		return op1 / op2;
	}
	return INT_MIN;
}

int solve() {
	vector<int> nums(4);
	for (auto &x : nums) cin >> x;

	int res = INT_MIN;
	
	// always, ALWAYS sort before next_permutation
	sort(begin(nums), end(nums));
	do {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					// case 1
					int t1 = calc(i, nums[0], nums[1]);
					if (t1 == INT_MIN) continue;
					int t2 = calc(j, t1, nums[2]);
					if (t2 == INT_MIN) continue;
					int t3 = calc(k, t2, nums[3]);
					if (t3 == INT_MIN) continue;
					if (t3 <= 24) res = max(res, t3);
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					// case 2
					int t1 = calc(i, nums[0], nums[1]);
					if (t1 == INT_MIN) continue;
					int t2 = calc(j, nums[2], nums[3]);
					if (t2 == INT_MIN) continue;
					int t3 = calc(k, t1, t2);
					if (t3 == INT_MIN) continue;
					if (t3 <= 24) res = max(res, t3);
				}
			}
		}
	} while (next_permutation(begin(nums), end(nums)));

	cout << res << '\n';
	return 0;
}

int main() {
	int T; cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
