#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ifstream fin("rental.in");
	ofstream fout("rental.out");

	int N, M, R; fin >> N >> M >> R;
	vector<int> produce(N), rental(R);
	vector<pair<int, int>> milk(M);
	for (auto &x : produce) fin >> x;
	for (auto &x : milk) fin >> x.second >> x.first;
	for (auto &x : rental) fin >> x;
	sort(begin(produce), end(produce));
	sort(begin(milk), end(milk));
	sort(begin(rental), end(rental));

	vector<ll> prefix(N), suffix(N);

	for (int i = 0; i < N; i++) {
		if (i < R) prefix[i] = rental[R-1-i];
		if (i) prefix[i] += prefix[i-1];
	}

	int farm = M-1;
	for (int i = N-1; i >= 0; i--) {
		ll price = 0;

		while (farm >= 0) {
			if (produce[i] >= milk[farm].second) {
				price += 1LL * milk[farm].first * milk[farm].second;
				produce[i] -= milk[farm].second;
				farm--;
			} else {
				price += 1LL * milk[farm].first * produce[i];
				milk[farm].second -= produce[i];
				break;
			}
		}

		suffix[i] = price;
		if (i < N-1) suffix[i] += suffix[i+1];
	}

	ll best = 0;
	for (int i = 1; i < N; i++) {
		best = max(best, prefix[i-1] + suffix[i]);
	}
	best = max({suffix[0], best, prefix[N-1]});
	fout << best << endl;

	return 0;
}
