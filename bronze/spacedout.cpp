#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector<vector<int>> jar(N, vector<int>(N));
	for (auto &rows : jar) {
		for (auto &e : rows) {
			cin >> e;
		}
	}

	vector<int> rowsums(N);
	for (int i = 0; i < N; i++) {
		int oddsum = 0, evensum = 0;
		for (int j = 0; j < N; j++) {
			if (j % 2) oddsum += jar[i][j];
			else evensum += jar[i][j];
		}
		rowsums[i] = (evensum > oddsum ? evensum : oddsum);
	}

	vector<int> colsums(N);
	for (int j = 0; j < N; j++) {
		int oddsum = 0, evensum = 0;
		for (int i = 0; i < N; i++) {
			if (i % 2) oddsum += jar[i][j];
			else evensum += jar[i][j];
		}
		colsums[j] = (evensum > oddsum ? evensum : oddsum);
	}

	int Trow = accumulate(begin(rowsums), end(rowsums), 0);
	int Tcol = accumulate(begin(colsums), end(colsums), 0);
	cout << (Trow > Tcol ? Trow : Tcol) << '\n';

	return 0;
}
