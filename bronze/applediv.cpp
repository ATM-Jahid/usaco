#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	
	vector<int> jar(n);
	ll sum = 0;
	for (auto &x : jar) {
		cin >> x;
		sum += x;
	}

	ll res = sum;
	for (int b = 0; b < int(pow(2, n)); b++) {
		ll y = 0;
		for (int i = 0; i < n; i++) {
			if (b & int(pow(2, i))) {
				y += jar[i];
			}
		}
		res = min(res, abs(sum-2*y));
	}

	cout << res << '\n';
	return 0;
}
