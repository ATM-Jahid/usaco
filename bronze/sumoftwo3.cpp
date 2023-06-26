#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, sum; cin >> n >> sum;
	vector<pair<int, int>> jar(n);
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		jar[i] = {t, i+1};
	}
	sort(begin(jar), end(jar));

	int left = 0, right = n-1;
	while (left < right) {
		if (jar[left].first + jar[right].first < sum) {
			left++;
		} else if (jar[left].first + jar[right].first > sum) {
			right--;
		} else {
			cout << jar[left].second << ' ' << jar[right].second << '\n';
			return 0;
		}
	}

	cout << "IMPOSSIBLE\n";
	return 0;
}
