#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ifstream fin("reststops.in");
	ofstream fout("reststops.out");

	int l, n, rf, rb;
	fin >> l >> n >> rf >> rb;
	vector<pair<int, int>> stops(n);
	for (auto &[x, c] : stops) fin >> x >> c;

	vector<int> suff(n);
	suff[n-1] = stops[n-1].second;
	for (int i = n-2; i >= 0; i--) {
		suff[i] = max(stops[i].second, suff[i+1]);
	}

	ll t, tastiness = 0;
	for (int i = 0; i < n; i++) {
		t = 1LL * (rf-rb) * (stops[i].first - (i ? stops[i-1].first : 0));
		tastiness += 1LL * suff[i] * t;
	}

	fout << tastiness << endl;
	return 0;
}
