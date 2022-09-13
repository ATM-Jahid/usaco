#include <bits/stdc++.h>
using namespace std;

int main() {
	int x1 = 0, y1 = 0;
	int x2, y2, m, n, p, q;
	cin >> x2 >> y2 >> m >> n >> p >> q;

	int time = 0;
	while (x1 < x2 && y1 < y2) {
		x1 += m; y1 += n;
		x2 -= p; y2 -= q;
		time++;
	}

	if (x1 == x2 && y1 == y2) cout << time << '\n';
	else cout << "-1\n";

	return 0;
}
