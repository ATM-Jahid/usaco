#include <bits/stdc++.h>
using namespace std;

int solve() {
	int W, C, P; cin >> W >> C >> P;
	vector<string> nouns, t_verbs, i_verbs, junctions;
	for (int i = 0; i < W; i++) {
		string a, b; cin >> a >> b;
		if (b == "noun") {
			nouns.push_back(a);
		} else if (b == "transitive-verb") {
			t_verbs.push_back(a);
		} else if (b == "intransitive-verb") {
			i_verbs.push_back(a);
		} else if (b == "conjunction") {
			junctions.push_back(a);
		} else {
			return -1;
		}
	}

	int N = nouns.size(), T = t_verbs.size(),
		I = i_verbs.size(), J = junctions.size();

	J = (J > P) ? P : J;
	vector<int> tmp = {P+J, T+I, N};
	// L = maximum possible clauses
	int L = *min_element(begin(tmp), end(tmp));

	int max_wc = 0, max_i = 0, max_t = 0;
	for (int t = 0; t <= T; t++) {
		for (int i = 0; i <= I; i++) {
			if (t + i <= L && 2*t + i <= N) {
				int wc = 3*t + 2*i;
				if (t) {
					wc += min(N - 2*t - i, C);
				}
				wc += ((i+t)/2 > J) ? J : (i+t)/2;
				if (wc > max_wc) {
					max_wc = wc;
					max_i = i;
					max_t = t;
				}
			}
		}
	}
	cout << max_wc << '\n';

	if (max_wc) {
		vector<string> clauses(max_i+max_t);
		for (int i = 0; i < max_i; i++) {
			clauses[i] = nouns[i] + ' ' + i_verbs[i];
		}
		for (int t = 0; t < max_t; t++) {
			clauses[max_i+t] = nouns[max_i+t] + ' ' + t_verbs[t] + ' '
				+ nouns[max_i+max_t+t];
		}
		if (max_t) {
			int ext = min(N - 2*max_t - max_i, C);
			for (int k = 0; k < ext; k++) {
				clauses[max_i+max_t-1] += ", " + nouns[N-k-1];
			}
		}

		int cc = 0;
		for (int k = 0; k < max_i+max_t-1; k++) {
			if (cc % 2 == 0 && !junctions.empty()) {
				cout << clauses[k] + ' ' + junctions.back() + ' ';
				junctions.pop_back();
				cc++;
			} else {
				cout << clauses[k] + ". ";
				cc++;
			}
		}
		cout << clauses[max_i+max_t-1] << ".\n";
	} else {
		cout << '\n';
	}

	return 0;
}

int main() {
	int T; cin >> T;

	while(T--) {
		solve();
	}

	return 0;
}
