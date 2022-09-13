#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);

	int px1, py1, px2, py2;
	int qx1, qy1, qx2, qy2;
	cin >> px1 >> py1 >> px2 >> py2;
	cin >> qx1 >> qy1 >> qx2 >> qy2;

	int width = max(px2, qx2) - min(px1, qx1);
	int length = max(py2, qy2) - min(py1, qy1);
	int side = max(width, length);

	cout << side * side << '\n';
	return 0;
}
