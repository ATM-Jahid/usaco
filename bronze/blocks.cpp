#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);

	int n; cin >> n;
	vector<string> fir(n), sec(n);
	for (int i = 0; i < n; i++) {
		cin >> fir[i] >> sec[i];
	}

	for (char ch = 'a'; ch < 123; ch++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += max(count(fir[i].begin(), fir[i].end(), ch),
				count(sec[i].begin(), sec[i].end(), ch));
		}
		cout << cnt << '\n';
	}
	return 0;
}
