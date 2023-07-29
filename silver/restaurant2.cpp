#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<pair<int, int>> times;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		times.push_back({a, 1});
		times.push_back({b, -1});
	}
	sort(begin(times), end(times));

	int curr = 0, most = 0;
	for (auto &t : times) {
		curr += t.second;
		most = max(most, curr);
	}
	cout << most << endl;

	return 0;
}
