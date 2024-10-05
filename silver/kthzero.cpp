#include <bits/stdc++.h>
using namespace std;

int getSum(int l, int r) {
	cout << "? " << l << " " << r << endl;
	int sum; cin >> sum;
	return sum;
}

int first_true(int lo, int hi, function<bool(int)> fn) {
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (fn(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
	int n, k;
	cin >> n >> k >> k;

	int ans = first_true(1, n, [&](int pos) {
		int sum = getSum(1, pos);
		return (pos - sum) >= k;
	});

	cout << "! " << ans << endl;
	return 0;
}
