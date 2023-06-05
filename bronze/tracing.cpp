#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main () {
	ifstream fin("tracing.in");
	ofstream fout("tracing.out");

	int N, T;
	fin >> N >> T;

	vector<char> true_infected(N);
	for (auto &x : true_infected) fin >> x;

	vector<int> num_interact(N);
	vector<tuple<int, int, int>> tcards(T);
	for (auto &x : tcards) {
		int t, a, b; fin >> t >> a >> b;
		num_interact[a-1]++; num_interact[b-1]++;
		x = {t, a, b};
	}
	sort(begin(tcards), end(tcards));

	int Kmin = 256, Kmax = -1;
	int Klim = *max_element(begin(num_interact), end(num_interact));

	vector<int> sim_zpatient(N);
	for (int i = 0; i < N; i++) {
		if (true_infected[i] == '1') {
			for (int k = 0; k < Klim+1; k++) {
				vector<pii> sim_interact(N);
				sim_interact[i].first = 1;
				for (int t = 0; t < T; t++) {
					int c1 = get<1>(tcards[t])-1, c2 = get<2>(tcards[t])-1;
					if (sim_interact[c1].first==1 && sim_interact[c2].first==0) {
						sim_interact[c1].second += 1;
						if (sim_interact[c1].second <= k) {
							sim_interact[c2].first = 1;
						}
					} else if (sim_interact[c1].first==0 && sim_interact[c2].first==1) {
						sim_interact[c2].second += 1;
						if (sim_interact[c2].second <= k) {
							sim_interact[c1].first = 1;
						}
					} else if (sim_interact[c1].first==1 && sim_interact[c2].first==1) {
						sim_interact[c1].second += 1;
						sim_interact[c2].second += 1;
					}
				}
				int cond = 1;
				for (int j = 0; j < N; j++) {
					if (sim_interact[j].first != int(true_infected[j]-'0')) {
						cond = 0;
						break;
					}
				}
				if (cond) {
					sim_zpatient[i] += 1;
					Kmin = min(Kmin, k);
					Kmax = max(Kmax, k);
				}
			}
		}
	}

	int pzeros = 0;
	for (auto x : sim_zpatient) {
		if (x > 0) {
			pzeros += 1;
		}
	}

	if (Kmax == Klim) {
		fout << pzeros << " " << Kmin << " Infinity\n";
	} else {
		fout << pzeros << " " << Kmin << " " << Kmax << "\n";
	}

	return 0;
}
