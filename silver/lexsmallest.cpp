#include <bits/stdc++.h>
using namespace std;

bool cmp(string &a, string&b) {
	if (a.size() == b.size()) return a < b;
	else return a + b < b + a;
}

int main() {
	int n; cin >> n;
	vector<string> jar(n);
	for (auto &x : jar) cin >> x;

	sort(begin(jar), end(jar), cmp);
	for (auto &x : jar) cout << x;
	cout << endl;

	return 0;
}
