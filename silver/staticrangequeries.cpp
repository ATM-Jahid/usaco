#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N, Q; cin >> N >> Q;
	vector<int> l(N), r(N), v(N);
	set<int> pos_set;
	for (int i = 0; i < N; i++) {
		cin >> l[i] >> r[i] >> v[i];
		pos_set.insert(l[i]);
		pos_set.insert(r[i]);
	}
	pos_set.insert(0);
	pos_set.insert(1e9);

	vector<int> pos_vec(begin(pos_set), end(pos_set));
	vector<int> val(pos_vec.size());
	for (int i = 0; i < N; i++) {
		int d1 = distance(begin(pos_vec),
				lower_bound(begin(pos_vec), end(pos_vec), l[i]));
		int d2 = distance(begin(pos_vec),
				lower_bound(begin(pos_vec), end(pos_vec), r[i]));
		val[d1] += v[i];
		val[d2] -= v[i];
	}
	for (int i = 1; i < val.size(); i++) {
		val[i] += val[i-1];
	}
	//for (auto &x : pos_vec) cout << x << ' ';
	//cout << endl;
	//for (auto &x : val) cout << x << ' ';
	//cout << endl;

	while (Q--) {
		ll sum = 0;
		int p, q; cin >> p >> q;

		int d1 = distance(begin(pos_vec),
				lower_bound(begin(pos_vec), end(pos_vec), p));
		int d2 = distance(begin(pos_vec),
				lower_bound(begin(pos_vec), end(pos_vec), q));
		//cout << d1 << ' ' << d2 << endl;

		if (d1 == d2) {
			cout << 1LL * (q - p) * val[d1-1] << '\n';
			continue;
		}

		if (p != pos_vec[d1]) {
			sum += 1LL * (pos_vec[d1] - p) * val[d1-1];
		}
		if (q != pos_vec[d2]) {
			sum += 1LL * (q - pos_vec[d2-1]) * val[d2-1];
			d2--;
		}
		for (int i = d1; i < d2; i++) {
			sum += 1LL * (pos_vec[i+1] - pos_vec[i]) * val[i];
		}

		cout << sum << '\n';
	}

	return 0;
}
