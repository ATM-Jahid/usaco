#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("berries.in");
	ofstream fout("berries.out");
	
	int n, k; fin >> n >> k;
	vector<int> berries(n);
	for (auto &x : berries) fin >> x;

	int ans = 0;
	for (int b = 1; b <= 1000; b++) {
		int baskets = 0;
		for (int i = 0; i < n; i++) {
			baskets += berries[i] / b;
		}

		if (baskets >= k) {
			ans = max(ans, b * k/2);
		} else if (baskets >= k/2) {
			int need = k - baskets, sum = b * (baskets - k/2);
			sort(begin(berries), end(berries), [&](auto &l, auto &r) {
				return (l % b) > (r % b);
			});
			for (int in = 0; in < need; in++) {
				sum += berries[in] % b;
			}
			ans = max(ans, sum);
		} else {
			break;
		}
	}

	fout << ans << endl;
	return 0;
}
