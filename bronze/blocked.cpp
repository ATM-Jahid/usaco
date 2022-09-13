#include <bits/stdc++.h>
using namespace std;

int covered(int p, int q, int x1, int y1, int x2, int y2) {
	return x1 <= p && p <= x2 && y1 <= q && q <= y2;
}

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;
	cin >> x3 >> y3 >> x4 >> y4;

	int corn = 0;
	if (covered(x1, y1, x3, y3, x4, y4)) corn++;
	if (covered(x2, y1, x3, y3, x4, y4)) corn++;
	if (covered(x2, y2, x3, y3, x4, y4)) corn++;
	if (covered(x1, y2, x3, y3, x4, y4)) corn++;

	if (corn == 4) {
		cout << "0\n";
	} else if (corn == 2) {
		int width = max(0, min(x2, x4) - max(x1, x3));
		int length = max(0, min(y2, y4) - max(y1, y3));
		cout << (x2-x1)*(y2-y1) - width*length << '\n';
	} else {
		cout << (x2-x1)*(y2-y1) << '\n';
	}

	return 0;
}
