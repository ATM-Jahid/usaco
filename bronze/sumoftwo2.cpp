#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, sum; cin >> n >> sum;
	vector<int> jar(n);
	for (auto &x : jar) cin >> x;

	map<int, int> exist; // <val, place>
	for (int i = 0; i < n; i++) {
		if (exist.count(sum - jar[i])) {
			cout << exist[sum - jar[i]] << ' ' << i+1 << '\n';
			return 0;
		}
		exist[jar[i]] = i+1;
	}

	cout << "IMPOSSIBLE\n";
	return 0;
}
