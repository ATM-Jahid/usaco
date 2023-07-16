#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("maxcross.in");
	ofstream fout("maxcross.out");

	int N, K, B; fin >> N >> K >> B;
	vector<int> jar(N+1);
	for (int i = 0; i < B; i++) {
		int x; fin >> x;
		jar[x] = 1;
	}
	for (int i = 1; i <= N; i++) {
		jar[i] = jar[i-1] + jar[i];
	}

	int ans = INT_MAX;
	for (int i = K; i <= N; i++) {
		ans = min(ans, jar[i]-jar[i-K]);
	}

	fout << ans << '\n';
	return 0;
}
