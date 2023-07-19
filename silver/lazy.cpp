#include <bits/stdc++.h>
using namespace std;

int jar[800][800];

int main() {
	ifstream fin("lazy.in");
	ofstream fout("lazy.out");

	int N, K; fin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			fin >> jar[i+j-1][N-i+j];
		}
	}

	for (int i = 1; i <= 2*N-1; i++) {
		for (int j = 1; j <= 2*N-1; j++) {
			jar[i][j] += jar[i-1][j] + jar[i][j-1] - jar[i-1][j-1];
		}
	}

	K = 2*K+1;
	int ans = -1;
	for (int i = K; i <= 2*N-1; i++) {
		for (int j = K; j <= 2*N-1; j++) {
			int foo = jar[i][j] - jar[i-K][j] - jar[i][j-K] + jar[i-K][j-K];
			ans = max(ans, foo);
		}
	}

	if (ans == -1) fout << jar[2*N-1][2*N-1] << '\n';
	else fout << ans << '\n';

	return 0;
}
