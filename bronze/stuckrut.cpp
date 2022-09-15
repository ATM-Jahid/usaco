#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<array<int, 3>> ncows, ecows;
	for (int i = 0; i < n; i++) {
		char dir; int x, y;
		cin >> dir >> x >> y;
		if (dir == 'N') ncows.push_back({x, y, i});
		else if (dir == 'E') ecows.push_back({x, y, i});
		else return -1;
	}

	sort(ncows.begin(), ncows.end());
	sort(ecows.begin(), ecows.end(), [](auto &left, auto &right) {
		return left[1] < right[1];
	});

	vector<int> dist(n);
	for (auto &ec : ecows) {
		for (auto &nc : ncows) {
			if (nc[0] > ec[0] && nc[1] < ec[1] && !dist[nc[2]]) {
				if (ec[1] - nc[1] > nc[0] - ec[0]) {
					dist[nc[2]] = ec[1] - nc[1];
				} else if (ec[1] - nc[1] < nc[0] - ec[0]) {
					dist[ec[2]] = nc[0] - ec[0];
					break;
				}
			}
		}
	}

	for (auto el : dist) {
		if (el) cout << el << '\n';
		else cout << "Infinity\n";
	}
	return 0;
}
