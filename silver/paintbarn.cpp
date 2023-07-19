#include <bits/stdc++.h>
using namespace std;

int barn[1002][1002];

int main() {
	ifstream fin("paintbarn.in");
	ofstream fout("paintbarn.out");

	int N, K; fin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b, A, B; fin >> a >> b >> A >> B;
		barn[a+1][b+1]++;
		barn[a+1][B+1]--;
		barn[A+1][b+1]--;
		barn[A+1][B+1]++;
	}

	int ans = 0;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			barn[i][j] += barn[i-1][j] + barn[i][j-1] - barn[i-1][j-1];
			if (barn[i][j] == K) ans++;
		}
	}
	fout << ans << '\n';

	return 0;
}
