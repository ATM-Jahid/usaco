#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("lifeguards.in");
	ofstream fout("lifeguards.out");

	int N; fin >> N;
	vector<int> a(N), b(N), pos;
	for (int i = 0; i < N; i++) {
		fin >> a[i] >> b[i];
		pos.push_back(a[i]);
		pos.push_back(b[i]);
	}
	sort(begin(pos), end(pos));
	int L = pos.size();

	vector<int> cov(L);
	for (int i = 0; i < N; i++) {
		int d1 = distance(begin(pos),
				lower_bound(begin(pos), end(pos), a[i]));
		int d2 = distance(begin(pos),
				lower_bound(begin(pos), end(pos), b[i]));
		cov[d1]++;
		cov[d2]--;
	}
	for (int i = 1; i < L; i++) {
		cov[i] += cov[i-1];
	}

	vector<int> ones(L);
	for (int i = 1; i < L; i++) {
		ones[i] = ones[i-1] + (cov[i-1] == 1) * (pos[i] - pos[i-1]);
	}

	int curr = 0;
	for (int i = 0; i < L-1; i++) {
		if (cov[i]) curr += pos[i+1] - pos[i];
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int d1 = distance(begin(pos),
				lower_bound(begin(pos), end(pos), a[i]));
		int d2 = distance(begin(pos),
				lower_bound(begin(pos), end(pos), b[i]));
		int sub = ones[d2] - ones[d1];
		ans = max(ans, curr - sub);
	}
	fout << ans << endl;

	return 0;
}
