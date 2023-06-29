#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);

	int N, M, K; cin >> N >> M >> K;
	vector<int> hier(M);
	int dir = -1;
	for (auto &x : hier) {
		cin >> x;
		if (x == 1) {
			dir = 1;
		}
	}
	vector<int> order(N);
	map<int, int> pos;
	for (int i = 0, x, y; i < K; i++) {
		cin >> x >> y;
		if (x == 1) {
			cout << y << '\n';
			return 0;
		}
		order[y-1] = x;
		pos[x] = y-1;
	}

	if (dir == 1) {
		int left = 0;
		for (int i = 0; i < M; i++) {
			if (pos.count(hier[i])) {
				left = pos[hier[i]] + 1;
			} else if (order[left] > 0) {
				left++;
				i--;
			} else {
				order[left] = hier[i];
				if (hier[i] == 1) {
					cout << left+1 << '\n';
					return 0;
				}
			}
		}
	} else {
		int right = N-1;
		for (int i = M-1; i >= 0; i--) {
			if (pos.count(hier[i])) {
				right = pos[hier[i]] - 1;
			} else if (order[right] > 0) {
				right--;
				i++;
			} else {
				order[right] = hier[i];
			}
		}
		for (int i = 0; i < N; i++) {
			if (order[i] == 0) {
				cout << i+1 << '\n';
				return 0;
			}
		}
	}

	return 0;
}
