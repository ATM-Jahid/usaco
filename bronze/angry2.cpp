#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> pos;

int explode(int init, int dir) {
	int rad = 1, prev = init;

	while (true) {
		int next = prev;

		while (next+dir >= 0 && next+dir < N &&
				abs(pos[next+dir] - pos[prev]) <= rad) {
			next += dir;
		}

		if (next == prev) break;

		prev = next;
		rad++;
	}

	return abs(prev - init);
}

int main() {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

	cin >> N;
	pos.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> pos[i];
	}
	sort(begin(pos), end(pos));

	int res = 0;
	for (int i = 0; i < N; i++) {
		res = max(res, explode(i, 1) + explode(i, -1) + 1);
	}

	cout << res << '\n';
	return 0;
}
