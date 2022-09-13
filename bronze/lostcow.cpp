#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);

	int x, y; cin >> x >> y;
	int low = x, high = x;

	int dist = 0;
	for (int i = 0; i < 13; i++) {
		if (i % 2 == 0) {
			high = x + pow(-2, i);
			if (low <= y && y <= high) {
				dist += y - low;
				break;
			}
		} else {
			low = x + pow(-2, i);
			if (low <= y && y <= high) {
				dist += high - y;
				break;
			}
		}
		dist += high - low;
	}

	cout << dist << '\n';
	return 0;
}
