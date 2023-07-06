#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int> jar(N);

	vector<int> diff;
	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		if (c == 'H') jar[i] = 0;
		else if (c == 'G') jar[i] = 1;
		if (i % 2 && jar[i-1] != jar[i]) {
			diff.push_back(jar[i-1] - jar[i]);
		}
	}

	int cnt = 0, D = diff.size();
	for (int i = 0; i < D; i++) {
		if (diff[i] > 0) {
			while (++i < D && diff[i] > 0);
			i--;
			cnt++;
		}
	}

	if (cnt == 0) {
		cout << "0\n";
	} else {
		cout << (diff[0] < 0 ? 2*cnt : 2*cnt-1) << '\n';
	}

	return 0;
}
