#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	multiset<int> h;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		h.insert(tmp);
	}

	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		auto it = h.upper_bound(tmp);

		if (h.begin() == it) {
			cout << "-1\n";
		} else {
			cout << *(--it) << '\n';
			h.erase(it);
		}
	}

	return 0;
}
