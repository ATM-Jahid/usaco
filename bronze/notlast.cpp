#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);

	int N; cin >> N;
	map<string, int> produce;
	for (int i = 0; i < N; i++) {
		string cow; cin >> cow;
		int amt; cin >> amt;
		produce[cow] += amt;
	}

	int last = INT_MAX;
	if (produce.size() < 7) {
		last = 0;
	} else {
		for (auto &x : produce) {
			if (x.second < last) last = x.second;
		}
	}

	string notlast;
	int seclast = INT_MAX, cnt = 0;
	for (auto &x : produce) {
		if (x.second != last && x.second < seclast) {
			seclast = x.second;
			cnt = 1;
			notlast = x.first;
		} else if (x.second == seclast) {
			cnt++;
		}
	}

	cout << (cnt == 1 ? notlast : "Tie") << '\n';
	return 0;
}
