#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> jar(n);
	for (auto &x : jar) cin >> x;

	int sorted = 0, moo = 0;
	while (!sorted) {
		sorted = 1;
		moo++;
		for (int i = 0; i < n-1; i++) {
			if (jar[i+1] < jar[i]) {
				swap(jar[i], jar[i+1]);
				sorted = 0;
			}
		}
	}

	cout << moo << endl;

	return 0;
}
