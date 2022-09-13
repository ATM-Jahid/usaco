#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("promote.in");
	ofstream fout("promote.out");

	int before[4], after[4], p[4];
	for (int i = 0; i < 4; i++) {
		fin >> before[i] >> after[i];
	}

	p[3] = 0;
	for (int i = 2; i > -1; i--) {
		p[i] = after[i+1] - before[i+1] + p[i+1];
	}

	for (int i = 0; i < 3; i++) {
		fout << p[i] << '\n';
	}

	return 0;
}
