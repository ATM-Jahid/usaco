#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	sort(begin(a), end(a));

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum > x) {
			cout << i << endl;
			return 0;
		}
	}

	cout << n << endl;
	return 0;
}
