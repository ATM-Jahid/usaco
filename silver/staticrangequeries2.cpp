#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N, Q; cin >> N >> Q;
	vector<int> cmp_pos;
	vector<int> upl(N), upr(N), upv(N);
	for (int i = 0; i < N; i++) {
		cin >> upl[i] >> upr[i] >> upv[i];
		cmp_pos.push_back(upl[i]);
		cmp_pos.push_back(upr[i]);
	}
	vector<int> ql(Q), qr(Q);
	for (int i = 0; i < Q; i++) {
		cin >> ql[i] >> qr[i];
		cmp_pos.push_back(ql[i]);
		cmp_pos.push_back(qr[i]);
	}

	sort(begin(cmp_pos), end(cmp_pos));
	cmp_pos.erase(
			unique(begin(cmp_pos), end(cmp_pos)),
			end(cmp_pos));
	int L = cmp_pos.size();
	vector<int> val(L);

	for (int i = 0; i < N; i++) {
		int d1 = distance(begin(cmp_pos),
				lower_bound(begin(cmp_pos), end(cmp_pos), upl[i]));
		int d2 = distance(begin(cmp_pos),
				lower_bound(begin(cmp_pos), end(cmp_pos), upr[i]));
		val[d1] += upv[i];
		val[d2] -= upv[i];
	}
	for (int i = 1; i < L; i++) {
		val[i] += val[i-1];
	}

	vector<ll> pref(L);
	for (int i = 1; i < L; i++) {
		pref[i] = pref[i-1] + 1LL * val[i-1] * (cmp_pos[i] - cmp_pos[i-1]);
	}

	for (int i = 0; i < Q; i++) {
		int d1 = distance(begin(cmp_pos),
				lower_bound(begin(cmp_pos), end(cmp_pos), ql[i]));
		int d2 = distance(begin(cmp_pos),
				lower_bound(begin(cmp_pos), end(cmp_pos), qr[i]));
		cout << pref[d2] - pref[d1] << '\n';
	}

	return 0;
}
