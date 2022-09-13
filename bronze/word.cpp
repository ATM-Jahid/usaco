#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	vector<string> jar(n);
	for (auto &x : jar) cin >> x;

	int cnt = 0;
	string buff = "";
	for (int i = 0; i < n; i++) {
		if (cnt + jar[i].length() > k) {
			buff.pop_back();
			cout << buff << '\n';
			cnt = jar[i].length();
			buff = jar[i] + " ";
		} else {
			cnt += jar[i].length();
			buff += jar[i] + " ";
		}
	}
	buff.pop_back();
	cout << buff << '\n';

	return 0;
}
