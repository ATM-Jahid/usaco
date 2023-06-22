#include <bits/stdc++.h>
using namespace std;

void board(int s, int mode, const vector<int> &x,
		const vector<int> &y, const vector<char> &porder) {
	if (mode == 1) {
		for (int k = 0; k < 3; k++) {
			for (int i = 0; i < y[k]; i++) {
				for (int j = 0; j < s; j++) cout << porder[k];
				cout << '\n';
			}
		}
	} else if (mode == 2) {
		for (int i = 0; i < y[0]; i++) {
			for (int j = 0; j < s; j++) cout << porder[0];
			cout << '\n';
		}
		for (int i = 0; i < y[1]; i++) {
			for (int j = 0; j < x[1]; j++) cout << porder[1];
			for (int j = 0; j < x[2]; j++) cout << porder[2];
			cout << '\n';
		}
	}
}

int main() {
	vector<int> x(3), y(3);
	cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

	int sq = -1;
	for (int i = 0; i < (1 << 3); i++) {
		// swap x and y
		vector<int> nx(3), ny(3);
		for (int j = 0; j < 3; j++) {
			if (i & (1 << j)) {
				nx[j] = y[j];
				ny[j] = x[j];
			} else {
				nx[j] = x[j];
				ny[j] = y[j];
			}
		}
		
		// indices to sort everything else
		vector<int> ind = {0, 1, 2};
		vector<char> ord = {'A', 'B', 'C'};
		
		// permutations of A B C
		do {
			vector<int> nnx = {nx[ind[0]], nx[ind[1]], nx[ind[2]]};
			vector<int> nny = {ny[ind[0]], ny[ind[1]], ny[ind[2]]};
			vector<char> nord = {ord[ind[0]], ord[ind[1]], ord[ind[2]]};

			if (nnx[0] == nnx[1] &&
					nnx[1] == nnx[2] &&
					nnx[0] == (nny[0]+nny[1]+nny[2])) {
				sq = nnx[0];
				cout << sq << '\n';
				board(sq, 1, nnx, nny, nord);
				return 0;
			} else if (nnx[0] == nnx[1] + nnx[2] &&
					nny[1] == nny[2] &&
					nnx[0] == (nny[0]+nny[1])) {
				sq = nnx[0];
				cout << sq << '\n';
				board(sq, 2, nnx, nny, nord);
				return 0;
			}
		} while(next_permutation(begin(ind), end(ind)));
	}

	if (sq < 0) cout << sq << '\n';
	return 0;
}
