#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, target;
	cin >> n >> target;
	vector<pair<int, int>> jar(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		jar[i] = {x, i+1};
	}
	sort(begin(jar), end(jar));

	for (int i = 0; i < n-2 && jar[i].first < target-1; i++) {
		int tofind = target - jar[i].first;
		int left = i+1, right = n-1;
		while (left < right) {
			if (jar[left].first + jar[right].first < tofind) {
				left++;
			} else if (jar[left].first + jar[right].first > tofind) {
				right--;
			} else {
				cout << jar[i].second << ' ' << jar[left].second << ' '
					<< jar[right].second << '\n';
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE\n";
	return 0;
}
