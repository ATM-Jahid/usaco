#include <bits/stdc++.h>
using namespace std;

vector<int> stalls(101);
vector<tuple<int, int, int, int>> airconds, subset;
int set_len, res = INT_MAX;

int recurse(int k) {
	if (k == set_len) {
		vector<int> foo = stalls;
		int cost = 0;

		for (auto &x : subset) {
			for (int i = get<0>(x); i <= get<1>(x); i++) {
				foo[i] -= get<2>(x);
			}
			cost += get<3>(x);
		}

		bool valid = true;
		for (auto &y : foo) {
			if (y > 0) {
				valid = false;
				break;
			}
		}
		if (valid) {
			res = min(res, cost);
		}

		return 0;
	} else {
		recurse(k+1);
		subset.push_back(airconds[k]);
		recurse(k+1);
		subset.pop_back();
	}

	return 0;
}

int main() {
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int s, t, c; cin >> s >> t >> c;
		for (int j = s; j < t+1; j++) {
			stalls[j] = c;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b, p, m; cin >> a >> b >> p >> m;
		airconds.push_back(tie(a, b, p, m));
	}
	set_len = airconds.size();

	recurse(0);
	cout << res << '\n';

	return 0;
}
