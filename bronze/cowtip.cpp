#include <bits/stdc++.h>
using namespace std;

ifstream fin("cowtip.in");
ofstream fout("cowtip.out");

int N;
vector<vector<int>> jar;

int iszero(int imax) {
	for (int i = 0; i <= imax; i++) {
		for (int j = 0; j < N; j++) {
			if (jar[i][j] == 1) {
				return 0;
			}
		}
	}
	return 1;
}

void flip(int imax, int jmax) {
	for (int i = 0; i <= imax; i++) {
		for (int j = 0; j <= jmax; j++) {
			if (jar[i][j] == 1) jar[i][j] = 0;
			else jar[i][j] = 1;
		}
	}
}

void print() {
	for (auto &row : jar) {
		for (auto &e : row) fout << e;
		fout << endl;
	}
	fout << endl;
}

int main() {
	fin >> N;
	jar.resize(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c; fin >> c;
			jar[i][j] = int(c-'0');
		}
	}

	int cnt = 0;
	for (int i = N-1; i >= 0 && !iszero(i); i--) {
		for (int j = N-1; j >= 0; j--) {
			if (jar[i][j] == 1) {
				flip(i, j);
				cnt++;
				//print();
			}
		}
	}

	fout << cnt << '\n';

	return 0;
}
