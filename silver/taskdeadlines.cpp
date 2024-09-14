#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<pair<int, int>> jar(n);
	for (auto &[f, s] : jar) cin >> f >> s;
	sort(begin(jar), end(jar));

	long long reward = 0, curr = 0;
	for (auto &[f, s] : jar) {
		curr += f;
		reward += s - curr;
	}

	cout << reward << endl;
	return 0;
}
