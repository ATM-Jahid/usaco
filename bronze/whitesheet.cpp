#include <bits/stdc++.h>
using namespace std;

int cov1D(int x1, int x2, int x3, int x4, int x5, int x6) {
	int sect = min(x4, x6) - max(x3, x5);
	if (sect < 0) {
		if ((x3 <= x1 && x2 <= x4) ||
			(x5 <= x1 && x2 <= x6)) {
			return 1;
		} else {
			return 0;
		}
	} else {
		if (min(x3, x5) <= x1 && x2 <= max(x4, x6)) {
			return 1;
		} else {
			return 0;
		}
	}
}

int covCorn(int x1, int y1, int x3, int y3, int x4, int y4) {
	return x3 <= x1 && x1 <= x4 && y3 <= y1 && y1 <= y4;
}

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;
	cin >> x3 >> y3 >> x4 >> y4;
	int x5, y5, x6, y6;
	cin >> x5 >> y5 >> x6 >> y6;

	int covered = cov1D(x1, x2, x3, x4, x5, x6) *
			cov1D(y1, y2, y3, y4, y5, y6);
	if (!covered) {
		cout << "YES\n";
		return 0;
	}

	int corners = 0;
	if (covCorn(x1, y1, x3, y3, x4, y4) || covCorn(x1, y1, x5, y5, x6, y6))
		corners++;
	if (covCorn(x2, y1, x3, y3, x4, y4) || covCorn(x2, y1, x5, y5, x6, y6))
		corners++;
	if (covCorn(x2, y2, x3, y3, x4, y4) || covCorn(x2, y2, x5, y5, x6, y6))
		corners++;
	if (covCorn(x1, y2, x3, y3, x4, y4) || covCorn(x1, y2, x5, y5, x6, y6))
		corners++;

	if (corners == 4) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
	return 0;
}
