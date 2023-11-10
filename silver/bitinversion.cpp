#include <bits/stdc++.h>
using namespace std;

string s;
int n, occ[200001];
set<int> changes;
priority_queue<int> most;

void modify(int x) {
	if (x == 0 || x == n) return;
	auto it = changes.find(x);
	if (it != end(changes)) {
		int l = *prev(it), r = *next(it);
		changes.erase(it);
		occ[x-l]--;
		occ[r-x]--;
		occ[r-l]++; most.push(r-l);
	} else {
		it = changes.insert(x).first;
		int l = *prev(it), r = *next(it);
		occ[x-l]++; most.push(x-l);
		occ[r-x]++; most.push(r-x);
		occ[r-l]--;
	}
}

int main() {
	cin >> s;
	n = s.size();

	changes.insert({0, n});
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i-1]) {
			changes.insert(i);
		}
	}

	for (auto it = begin(changes); next(it) != end(changes); it++) {
		int l = *next(it) - *it;
		occ[l]++;
		most.push(l);
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		modify(x-1);
		modify(x);
		while (!occ[most.top()]) most.pop();
		cout << most.top() << ' ';
	}

	return 0;
}
