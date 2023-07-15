#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("hps.in");
	ofstream fout("hps.out");

	int N; fin >> N;
	vector<int> H(N+1), P(N+1), S(N+1);
	for (int i = 1; i <= N; i++) {
		char c; fin >> c;
		H[i] = H[i-1]; P[i] = P[i-1]; S[i] = S[i-1];
		if (c == 'H') H[i]++;
		else if (c == 'P') P[i]++;
		else if (c == 'S') S[i]++;
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int left = max({H[i], P[i], S[i]});
		int right = max({H[N]-H[i], P[N]-P[i], S[N]-S[i]});
		ans = max(ans, left+right);
	}

	fout << ans << '\n';
	return 0;
}
