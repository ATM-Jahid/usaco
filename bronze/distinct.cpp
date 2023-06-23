#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> jar(n);
	for (auto &x : jar) cin >> x;
	sort(begin(jar), end(jar));

	int count = 1;
	for (int i = 0; i < n-1; i++) {
		if (jar[i] < jar[i+1]) {
			count++;
		}
	}

	cout << count << '\n';
	return 0;
}
