#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);

	int n; cin >> n;
	vector<int> loc(3), cnt(3);
	for (int i = 0; i < 3; i++) loc[i] = i;

	int a, b, g;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> g;
		a--; b--; g--;
		swap(loc[a], loc[b]);
		cnt[loc[g]]++;
	}

	cout << max({cnt[0], cnt[1], cnt[2]}) << '\n';
	return 0;
}
