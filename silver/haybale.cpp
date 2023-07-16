#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K; cin >> N >> K;
	vector<int> jar(N+2);
	for (int i = 0; i < K; i++) {
		int l, r; cin >> l >> r;
		jar[l]++;
		jar[r+1]--;
	}

	for (int i = 1; i <= N; i++) {
		jar[i] += jar[i-1];
	}
	sort(begin(jar)+1, end(jar)-1);

	cout << jar[N/2 + 1] << '\n';
	return 0;
}
