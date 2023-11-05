#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<int>> turistas;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		turistas.push_back({a, b, i});
	}
	sort(begin(turistas), end(turistas));

	int most = 0, last = 0;
	// min heap: <departure, room>
	priority_queue<vector<int>> heap;
	vector<int> assigned(n);

	for (auto &t : turistas) {
		if (heap.empty()) {
			last++;
			assigned[t[2]] = last;
			heap.push({-t[1], last});
		} else {
			vector<int> imm_dep = heap.top();
			if (-imm_dep[0] < t[0]) {
				heap.pop();
				assigned[t[2]] = imm_dep[1];
				heap.push({-t[1], imm_dep[1]});
			} else {
				last++;
				assigned[t[2]] = last;
				heap.push({-t[1], last});
			}
		}
		most = max(most, int(heap.size()));
	}

	cout << most << endl;
	for (auto &e : assigned) cout << e << ' ';
	cout << endl;

	return 0;
}
