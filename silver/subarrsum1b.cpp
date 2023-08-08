#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, target;
	cin >> n >> target;
	vector<int> jar(n);
	for (auto &x : jar) cin >> x;

	ll ans = 0, sum = 0;
	int left, right = 0;
	for (left = 0; left < n; left++) {
		while (right < n && sum + jar[right] <= target) {
			sum += jar[right];
			right++;
		}
		if (sum == target) ans++;
		sum -= jar[left];
	}

	cout << ans << endl;
	return 0;
}
