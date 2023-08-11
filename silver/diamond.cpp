#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("diamond.in");
	ofstream fout("diamond.out");

	int N, K;
	fin >> N >> K;
	vector<int> jar(N);
	for (auto &x : jar) fin >> x;
	sort(begin(jar), end(jar));

	int r = 0;
	vector<int> pref(N), suff(N);
	for (int i = 0; i < N; i++) {
		while (r < N && jar[r]-jar[i] <= K) {
			pref[r] = suff[i] = r - i + 1;
			if (r) pref[r] = max(pref[r-1], pref[r]);
			r++;
		}
	}

	for (int i = N-2; i >= 0; i--) {
		suff[i] = max(suff[i], suff[i+1]);
	}

	int best = 0;
	for (int i = 0; i < N-1; i++) {
		best = max(best, pref[i] + suff[i+1]);
	}
	fout << best << endl;

	return 0;
}
