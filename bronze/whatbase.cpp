#include <bits/stdc++.h>
using namespace std;

ifstream fin("whatbase.in");
ofstream fout("whatbase.out");

int solve() {
	int x, y; fin >> x >> y;

	map<int, int> xs, ys;
	for (int i = 10; i < 15001; i++) {
		int nX = (x % 10) + ((x/10) % 10) * i + ((x/100) % 10) * i * i;
		int nY = (y % 10) + ((y/10) % 10) * i + ((y/100) % 10) * i * i;
		xs[nX] = i;
		ys[nY] = i;
		if (xs.count(nY)) {
			fout << xs[nY] << ' ' << i << '\n';
			break;
		}
		if (ys.count(nX)) {
			fout << i << ' ' << ys[nX] << '\n';
			break;
		}
	}

	return 0;
}

int main() {
	int K; fin >> K;
	while (K--) {
		solve();
	}
	return 0;
}
