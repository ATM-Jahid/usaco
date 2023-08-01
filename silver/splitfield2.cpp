#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll sweep(vector<pii> &cows) {
	int n = cows.size();
	sort(begin(cows), end(cows));

	vector<pii> pref(n), suff(n);

	auto upd = [](pii &a, int &b) -> pii {
		return {max(a.first, b), min(a.second, b)};
	};

	pref[0] = {cows[0].second, cows[0].second};
	for (int i = 1; i < n; i++) {
		pref[i] = upd(pref[i-1], cows[i].second);
	}

	suff[n-1] = {cows[n-1].second, cows[n-1].second};
	for (int i = n-2; i >= 0; i--) {
		suff[i] = upd(suff[i+1], cows[i].second);
	}

	ll max_area = 1LL * (cows[n-1].first - cows[0].first) *
		(pref[n-1].first - pref[n-1].second);
	ll min_area = max_area;

	for (int i = 0; i < n-1; i++) {
		if (cows[i].first != cows[i+1].first) {
			ll left = 1LL * (cows[i].first - cows[0].first) *
				(pref[i].first - pref[i].second);
			ll right = 1LL * (cows[n-1].first - cows[i+1].first) *
				(suff[i+1].first - suff[i+1].second);
			min_area = min(min_area, left + right);
		}
	}

	return max_area - min_area;
}

int main() {
	ifstream fin("split.in");
	ofstream fout("split.out");

	int N; fin >> N;
	vector<pii> jar(N);
	for (auto &e : jar) fin >> e.first >> e.second;

	ll ans = sweep(jar);
	for (auto &e : jar) swap(e.first, e.second);
	ans = max(ans, sweep(jar));
	fout << ans << endl;

	return 0;
}
