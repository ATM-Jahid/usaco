#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	multiset<int> jar;

	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		jar.insert(k);
		auto it = jar.upper_bound(k);
		if (it != jar.end()) jar.erase(it);
	}

	cout << jar.size() << endl;
	return 0;
}
