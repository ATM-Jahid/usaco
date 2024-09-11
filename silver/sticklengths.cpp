#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> jar(n);
	for (auto &x : jar) cin >> x;
	sort(begin(jar), end(jar));

	int median = jar[n/2];
	long long sum = 0;
	for (auto &x : jar) sum += abs(x-median);

	cout << sum << endl;
	return 0;
}
