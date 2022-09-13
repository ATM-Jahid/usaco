#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	int px1, py1, px2, py2;
	int qx1, qy1, qx2, qy2;
	cin >> px1 >> py1 >> px2 >> py2;
	cin >> qx1 >> qy1 >> qx2 >> qy2;

	int sect_x = max(0, min(px2,qx2) - max(px1,qx1));
	int sect_y = max(0, min(py2,qy2) - max(py1,qy1));

	int ded;
	if ((px1 < qx1 && qx2 < px2) || (py1 < qy1 && qy2 < py2)) {
		ded = 0;
	} else if (sect_x == px2-px1 || sect_y == py2-py1) {
		ded = sect_x * sect_y;
	} else {
		ded = 0;
	}

	cout << (px2-px1)*(py2-py1) - ded << '\n';
	return 0;
}
