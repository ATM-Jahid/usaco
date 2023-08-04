#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int mod = 1000000007;

int cum(vector<array<int, 2>> &foo, vector<tuple<int, int, ll>> &pref,
		vector<tuple<int, int, ll>> &suff) {

	int curr = INT_MAX, run = 0;
	for (int i = 0; i < N; i++) {
		get<0>(pref[i]) = foo[i][0];
		get<1>(pref[i]) = foo[i][1];

		if (foo[i][0] == curr) run++;
		else {
			curr = foo[i][0];
			run = 0;
		}

		if (run) {
			get<2>(pref[i]) = get<2>(pref[i-1])
				+ 1LL * run * (foo[i][1] - foo[i-1][1]);
			get<2>(pref[i]) %= mod;
		}
	}

	curr = INT_MAX, run = 0;
	for (int i = N-1; i >= 0; i--) {
		get<0>(suff[i]) = foo[i][0];
		get<1>(suff[i]) = foo[i][1];

		if (foo[i][0] == curr) run++;
		else {
			curr = foo[i][0];
			run = 0;
		}

		if (run) {
			get<2>(suff[i]) = get<2>(suff[i+1])
				+ 1LL * run * (foo[i+1][1] - foo[i][1]);
			get<2>(suff[i]) %= mod;
		}
	}

	return 0;
}

int main() {
	ifstream fin("triangles.in");
	ofstream fout("triangles.out");

	fin >> N;
	vector<array<int, 2>> jar(N);
	for (auto &x : jar) fin >> x[0] >> x[1];
	sort(begin(jar), end(jar));

	vector<tuple<int, int, ll>> down(N), up(N), left(N), right(N);
	cum(jar, down, up);

	for (auto &x : jar) swap(x[0], x[1]);
	sort(begin(jar), end(jar));
	cum(jar, left, right);

	for (auto &x : left) swap(get<0>(x), get<1>(x));
	sort(begin(left), end(left));
	for (auto &x : right) swap(get<0>(x), get<1>(x));
	sort(begin(right), end(right));

	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += 1LL * ((get<2>(left[i]) + get<2>(right[i])) % mod)
			* ((get<2>(down[i]) + get<2>(up[i])) % mod);
		ans %= mod;
	}
	fout << ans << endl;

	return 0;
}
