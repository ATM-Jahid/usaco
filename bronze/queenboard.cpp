#include <bits/stdc++.h>
using namespace std;

int res = 0;

int recurse(int j, const vector<vector<char>> &foo) {
	if (j == 8) {
		res++;
		return 0;
	}

	for (int i = 0; i < 8; i++) {
		if (foo[i][j] == '.') {
			vector<vector<char>> bar = foo;

			for (int jj = j+1; jj < 8; jj++) {
				bar[i][jj] = '*';
			}
			for (int ii = i-min(i,7-j); ii <= i+min(7-i,7-j); ii++) {
				bar[ii][j+abs(ii-i)] = '*';
			}

			recurse(j+1, bar);
		}
	}

	return 0;
}

int main() {
	vector<vector<char>> jar(8, vector<char>(8));
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			cin >> jar[i][j];
		}
	}

	recurse(0, jar);

	cout << res << '\n';

	return 0;
}
