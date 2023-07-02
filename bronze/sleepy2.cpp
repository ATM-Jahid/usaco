#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);

	int N; cin >> N;
	vector<int> jar(N);
	for (auto &x : jar) cin >> x;

	int sorted = 1;
	for (int i = N-1; i > 0; i--) {
		if (jar[i] > jar[i-1]) {
			continue;
		} else {
			sorted = 0;
			cout << i << '\n';
			break;
		}
	}

	if (sorted) cout << 0 << '\n';
	return 0;
}
