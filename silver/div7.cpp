#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ifstream fin("div7.in");
	ofstream fout("div7.out");

	int N; fin >> N;
	vector<int> jar(N+1);
	for (int i = 1; i <= N; i++) {
		int t; fin >> t;
		jar[i] = jar[i-1] + t;
		jar[i] %= 7;
	}

	int ans = 0;
	for (int rem = 0; rem < 7; rem++) {
		int l = -1, r = -2;
		for (int j = 0; j <= N; j++) {
			if (jar[j] == rem) {
				l = j;
				break;
			}
		}
		for (int j = N; j >= 0; j--) {
			if (jar[j] == rem) {
				r = j;
				break;
			}
		}
		if (r > l) {
			ans = max(ans, r-l);
		}
	}

	fout << ans << '\n';
	return 0;
}
