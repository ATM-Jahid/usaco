#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);

	int n; cin >> n;
	char dir;
	int dst, x = 0, y = 0, time = 0;
	int ans = INT_MAX;
	map<pair<int, int>, int> jar;
	jar[{0, 0}] = 0;

	for (int i = 0; i < n; i ++) {
		cin >> dir >> dst;
		for (int j = 0; j < dst; j++) {
			time++;

			if (dir == 'N') y++;
			else if (dir == 'S') y--;
			else if (dir == 'E') x++;
			else if (dir == 'W') x--;
			else return -1;

			if (jar.count({x, y}) == 1) {
				ans = min(ans, time - jar[{x, y}]);
			}
			jar[{x, y}] = time;
		}
	}

	if (ans == INT_MAX) cout << "-1\n";
	else cout << ans << '\n';
	return 0;
}
