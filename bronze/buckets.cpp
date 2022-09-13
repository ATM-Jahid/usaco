#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);

	char c;
	int bx, rx, lx, by, ry, ly;
	for (int i = 0; i < 100; i++) {
		c = getchar();
		if (c == '\n') {
			i--;
		} else if (c != '.') {
			if (c == 'B') {
				by = i / 10;
				bx = i % 10;
			} else if (c == 'R') {
				ry = i / 10;
				rx = i % 10;
			} else if (c == 'L') {
				ly = i / 10;
				lx = i % 10;
			}
		}
	}

	int dbl = abs(lx - bx) + abs(ly - by);
	int dbr = abs(rx - bx) + abs(ry - by);
	int drl = abs(lx - rx) + abs(ly - ry);

	int ans;
	if ((bx == lx || by == ly) && (dbl == dbr + drl)) {
		ans = dbl + 1;
	} else {
		ans = dbl - 1;
	}

	cout << ans << '\n';
	return 0;
}
