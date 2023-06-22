#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;
set<int> posible;

int recurse(int k, const int &barn_aqui, const int &barn_alli,
		const vector<int> &buckets_aqui, const vector<int> &buckets_alli) {
	if (k == 4) {
		posible.insert(barn_aqui);
		return 0;
	} else {
		for (int i = 0; i < buckets_aqui.size(); i++) {
			int bb = buckets_aqui[i];

			vector<int> reduced = buckets_aqui;
			reduced.erase(begin(reduced)+i);

			vector<int> increased = buckets_alli;
			increased.push_back(bb);

			recurse(k+1, barn_alli+bb, barn_aqui-bb, increased, reduced);
		}
	}

	return 0;
}

int main() {
	freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);

	int t;
	for (int i = 0; i < 10; i++) {
		cin >> t;
		a.push_back(t);
	}
	for (int i = 0; i < 10; i++) {
		cin >> t;
		b.push_back(t);
	}

	recurse(0, 1000, 1000, a, b);
	cout << posible.size() << '\n';

	return 0;
}
