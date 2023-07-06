#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream cin("outofplace.in");
	ofstream cout("outofplace.out");
	
	int N; cin >> N;
	vector<int> jar(N);
	for (auto &x : jar) cin >> x;

	vector<int> foo = jar;
	sort(begin(foo), end(foo));

	if (foo == jar) {
		cout << "0\n";
		return 0;
	}

	int cnt = -1;
	for (int i = 0; i < N; i++) {
		if (jar[i] != foo[i]) cnt++;
	}
	cout << cnt << '\n';

	return 0;
}
