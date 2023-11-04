#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<int>> events;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		events.push_back({a, 0, i});
		events.push_back({b, 1, i});
	}
	sort(begin(events), end(events));
		
	vector<int> rooms;
	for (int i = n; i > 0; i--) {
		rooms.push_back(i);
	}

	int curr = 0, most = 0;
	vector<int> assigned(n);
	for (auto &ev : events) {
		if (ev[1]) {
			rooms.push_back(assigned[ev[2]]);
			curr--;
		} else {
			assigned[ev[2]] = rooms.back();
			rooms.pop_back();
			curr++;
		}
		most = max(most, curr);
	}

	cout << most << endl;
	for (auto &e : assigned) cout << e << ' ';
	cout << endl;

	return 0;
}
