#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N; cin >> N;
	vector<array<int, 2>> xsorted, ysorted;
	vector<int> unqx, unqy;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		xsorted.push_back({x, y});
		unqx.push_back(x);
		unqy.push_back(y);
	}
	ysorted = xsorted;
	sort(begin(xsorted), end(xsorted));
	sort(begin(ysorted), end(ysorted), [](auto &l, auto &r) {
		return l[1] < r[1];
	});
	sort(begin(unqx), end(unqx));
	sort(begin(unqy), end(unqy));
	unqx.erase(unique(begin(unqx), end(unqx)), end(unqx));
	unqy.erase(unique(begin(unqy), end(unqy)), end(unqy));
	int Lx = unqx.size(), Ly = unqy.size();

	ll max_area = 1LL * (ysorted[N-1][1] - ysorted[0][1]) *
		(xsorted[N-1][0] - xsorted[0][0]);

	vector<int> pref_dy(Lx), suff_dy(Lx);
	int curx = 0, maxy = 1, miny = 1e9;
	for (int i = 0; i < Lx; i++) {
		while (xsorted[curx][0] == unqx[i]) {
			maxy = max(maxy, xsorted[curx][1]);
			miny = min(miny, xsorted[curx][1]);
			curx++;
		}
		if (i) pref_dy[i] = max(pref_dy[i-1], maxy-miny);
		else pref_dy[i] = maxy-miny;
	}
	curx = N-1, maxy = 1, miny = 1e9;
	for (int i = Lx-1; i >= 0; i--) {
		while (xsorted[curx][0] == unqx[i]) {
			maxy = max(maxy, xsorted[curx][1]);
			miny = min(miny, xsorted[curx][1]);
			curx--;
		}
		if (i < Lx-1) suff_dy[i] = max(suff_dy[i+1], maxy-miny);
		else suff_dy[i] = maxy-miny;
	}

	vector<int> pref_dx(Ly), suff_dx(Ly);
	int cury = 0, maxx = 1, minx = 1e9;
	for (int i = 0; i < Ly; i++) {
		while (ysorted[cury][1] == unqy[i]) {
			maxx = max(maxx, ysorted[cury][0]);
			minx = min(minx, ysorted[cury][0]);
			cury++;
		}
		if (i) pref_dx[i] = max(pref_dx[i-1], maxx-minx);
		else pref_dx[i] = maxx-minx;
	}
	cury = N-1, maxx = 1, minx = 1e9;
	for (int i = Ly-1; i >= 0; i--) {
		while (ysorted[cury][1] == unqy[i]) {
			maxx = max(maxx, ysorted[cury][0]);
			minx = min(minx, ysorted[cury][0]);
			cury--;
		}
		if (i < Ly-1) suff_dx[i] = max(suff_dx[i+1], maxx-minx);
		else suff_dx[i] = maxx-minx;
	}

	ll min_area = max_area;
	for (int i = 0; i < Lx-1; i++) {
		ll l_area = 1LL * (unqx[i] - unqx[0]) * pref_dy[i];
		ll r_area = 1LL * (unqx[Lx-1] - unqx[i+1]) * suff_dy[i+1];
		min_area = min(min_area, l_area + r_area);
	}
	for (int i = 0; i < Ly-1; i++) {
		ll l_area = 1LL * (unqy[i] - unqy[0]) * pref_dx[i];
		ll r_area = 1LL * (unqy[Ly-1] - unqy[i+1]) * suff_dx[i+1];
		min_area = min(min_area, l_area + r_area);
	}
	cout << max_area - min_area << endl;

	return 0;
}
