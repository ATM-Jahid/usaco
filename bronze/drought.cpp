#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
	int N; cin >> N;
	vector<int> jar(N);
	for (auto &x : jar) cin >> x;

	ll bags = 0;
	for (int i = 1; i < N-1; i += 2) {
		if (jar[i-1] > jar[i]) {
			cout << "-1\n";
			return 0;
		} else {
			int d = jar[i] - jar[i-1];
			jar[i] -= d;
			jar[i+1] -= d;
			bags += 2LL * d;
		}
	}

	if (N % 2 == 0 && jar[N-1] != jar[N-2]) {
		cout << "-1\n";
		return 0;
	}
	int gmin = *min_element(begin(jar), end(jar));
	if (gmin < 0 || (N % 2 && jar[N-1] != gmin)) {
		cout << "-1\n";
		return 0;
	}

	for (auto &x : jar) {
		bags += 1LL * (x - gmin);
	}

	cout << bags << '\n';
	return 0;
}

int main() {
	int T; cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
