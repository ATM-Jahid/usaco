#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;
set<int> changes;
int cc = 0;

int recurse(int k) {
	if (k == 4) {
		changes.insert(cc);
		return 0;
	} else if (k % 2 == 0) {
		// from barn A to barn B
		int la = a.size();
		for (int i = 0; i < la; i++) {
			int buck = a[i];
			cc -= buck;
			a.erase(begin(a)+i);
			b.push_back(buck);

			recurse(k+1);

			cc += buck;
			a.insert(begin(a)+i, buck);
			b.pop_back();
		}
	} else if (k % 2 == 1) {
		// from barn B to barn A
		int lb = b.size();
		for (int i = 0; i < lb; i++) {
			int buck = b[i];
			cc += buck;
			b.erase(begin(b)+i);
			a.push_back(buck);

			recurse(k+1);

			cc -= buck;
			b.insert(begin(b)+i, buck);
			a.pop_back();
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

	recurse(0);
	cout << changes.size() << '\n';

	return 0;
}
