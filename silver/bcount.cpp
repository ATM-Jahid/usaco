#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("bcount.in");
	ofstream fout("bcount.out");

	int N, Q; fin >> N >> Q;
	vector<int> H(N+1), G(N+1), J(N+1);
	for (int i = 1; i <= N; i++) {
		int x; fin >> x;
		H[i] = H[i-1]; G[i] = G[i-1]; J[i] = J[i-1];
		if (x == 1) H[i]++;
		else if (x == 2) G[i]++;
		else if (x == 3) J[i]++;
	}

	for (int i = 0; i < Q; i++) {
		int l, r; fin >> l >> r;
		fout << H[r]-H[l-1] << ' ' << G[r]-G[l-1] << ' ' << J[r]-J[l-1] << '\n';
	}

	return 0;
}
