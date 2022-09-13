#include <bits/stdc++.h>
using namespace std;
using ll = long long;

tuple<int, int, int, int, int>
section(int x1, int y1, int x2, int y2,
	int x3, int y3, int x4, int y4) {
	int sect = 0;
	if (max(0, min(x2,x4)-max(x1,x3)) &&
		max(0, min(y2,y4)-max(y1,y3))) sect = 1;
	int lx = max(x1,x3), ly = max(y1,y3);
	int hx = min(x2,x4), hy = min(y2,y4);
	return {sect, lx, ly, hx, hy};
}

ll area(int x1, int y1, int x2, int y2) {
	return (ll) (x2 - x1) * (y2 - y1);
}

int main() {
	int x1, x2, x3, x4, x5, x6;
	int y1, y2, y3, y4, y5, y6;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	cin >> x5 >> y5 >> x6 >> y6;

	int sw1, sw2, sw3;
	int p1, p2, p3, p4, p5, p6;
	int q1, q2, q3, q4, q5, q6;
	ll area1 = 0, area2 = 0, secArea = 0;
	tie (sw1, p1, q1, p2, q2) = section(x1, y1, x2, y2, x3, y3, x4, y4);
	tie (sw2, p3, q3, p4, q4) = section(x1, y1, x2, y2, x5, y5, x6, y6);
	tie (sw3, p5, q5, p6, q6) = section(p1, q1, p2, q2, p3, q3, p4, q4);

	if (sw1) area1 = area(p1, q1, p2, q2);
	if (sw2) area2 = area(p3, q3, p4, q4);
	if (sw3) secArea = area(p5, q5, p6, q6);

	ll rem = area(x1, y1, x2, y2) - area1 - area2;
	if (area1 && area2) rem += secArea;

	if (rem) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
