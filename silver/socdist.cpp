#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll last_true(ll lo, ll hi, function<bool(ll)> fn) {
	for (ll dif = hi - lo; dif > 0; dif /= 2) {
		while (lo + dif <= hi && fn(lo + dif)) lo += dif;
	}
	return lo;
}

int main() {
	ifstream fin("socdist.in");
	ofstream fout("socdist.out");

	int N, M; fin >> N >> M;
	vector<pair<ll, ll>> grass(M);
	for (auto &[f, s] : grass) fin >> f >> s;
	sort(begin(grass), end(grass));

	fout << last_true(1, grass[M-1].second - grass[0].first, [&](ll d) {
		int num_cows = 1, p = 0;
		ll cur = grass[0].first, nxt;

		while (p < M) {
			nxt = cur + d;
			if (nxt <= grass[p].second) {
				num_cows++;
				cur = max(nxt, grass[p].first);
			} else {
				p++;
			}

			if (num_cows == N) return true;
		}

		return false;
	}) << endl;

	return 0;
}
