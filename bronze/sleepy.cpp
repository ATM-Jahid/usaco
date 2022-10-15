#include <bits/stdc++.h>
using namespace std;

int solve() {
	int N; cin >> N;
	vector<int> jar(N);

	int sum = 0;
	for (auto &el : jar) {
		cin >> el;
		sum += el;
	}

	for (int n = N; n > 0; n--) {
		if (sum % n == 0) {
			int k = sum / n, dd = 0;
			for (int i = 0; i < N; i++) {
				dd += jar[i];
				if (dd > k) break;
				else if (dd == k) dd = 0;
			}
			if (dd == 0) return N-n;
		}
	}

	return -1;
}

int main() {
	int T; cin >> T;

	while (T--) {
		cout << solve() << '\n';
	}

	return 0;
}
