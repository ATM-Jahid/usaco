#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, n;
	cin >> x >> n;

	set<int> lights;
	lights.insert(0);
	lights.insert(x);

	multiset<int> dist;
	dist.insert(x);

	for (int i = 0; i < n; i++) {
		int p; cin >> p;
		auto it = lights.upper_bound(p);
		int r = *it, l = *(--it);

		lights.insert(p);
		dist.erase(dist.find(r-l));
		dist.insert(r-p);
		dist.insert(p-l);

		cout << *dist.rbegin() << '\n';
	}

	return 0;
}
