#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int pasture[2501][2501];

int main() {
	int N; cin >> N;
	vector<int> xs(N), ys(N), ind1(N), ind2(N);
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		xs[i] = x; ys[i] = y;
	}

	iota(begin(ind1), end(ind1), 0);
	sort(begin(ind1), end(ind1), [&](auto &l, auto &r) {return xs[l] < xs[r];});
	for (int i = 0; i < N; i++) {
		xs[ind1[i]] = i+1;
	}
	iota(begin(ind2), end(ind2), 0);
	sort(begin(ind2), end(ind2), [&](auto &l, auto &r) {return ys[l] < ys[r];});
	for (int i = 0; i < N; i++) {
		ys[ind2[i]] = i+1;
	}

	for (int i = 0; i < N; i++) {
		pasture[xs[i]][ys[i]] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			pasture[i][j] += pasture[i-1][j] + pasture[i][j-1] - pasture[i-1][j-1];
		}
	}

	ll ans = N+1;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			int yleft, yright, xmin, xmax;
			yleft = min(ys[i], ys[j]); yright = max(ys[i], ys[j]);
			xmin = min(xs[i], xs[j]); xmax = max(xs[i], xs[j]);
			int rhs = pasture[xmax][N] - pasture[xmax][yright-1]
				- pasture[xmin-1][N] + pasture[xmin-1][yright-1];
			int lhs = pasture[xmax][yleft] - pasture[xmax][0]
				- pasture[xmin-1][yleft] + pasture[xmin-1][0];
			ans += rhs * lhs;
		}
	}

	cout << ans << '\n';
	return 0;
}
