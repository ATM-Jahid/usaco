#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("lemonade.in");
	ofstream fout("lemonade.out");

	int n; fin >> n;
	vector<int> waits(n);
	for (auto &x : waits) fin >> x;
	sort(begin(waits), end(waits));

	int cnt = 0;
	for (int i = n-1; i >= 0; i--) {
		if (waits[i] >= n-i-1) cnt++;
		else break;
	}

	fout << cnt << endl;
	return 0;
}
