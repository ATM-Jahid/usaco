#include <bits/stdc++.h>
using namespace std;

int grid[2001][2001];
int vert[2001][2001];
int hori[2001][2001];

int main() {
	int N, M, Q; cin >> N >> M >> Q;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char c; cin >> c;
			grid[i][j] = int(c-'0');
			if (grid[i][j] && grid[i-1][j]) vert[i][j] = 1;
			if (grid[i][j] && grid[i][j-1]) hori[i][j] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
			vert[i][j] += vert[i-1][j] + vert[i][j-1] - vert[i-1][j-1];
			hori[i][j] += hori[i-1][j] + hori[i][j-1] - hori[i-1][j-1];
		}
	}

	for (int q = 0; q < Q; q++) {
		int a, b, A, B; cin >> a >> b >> A >> B;
		int g = grid[A][B] - grid[a-1][B] - grid[A][b-1] + grid[a-1][b-1];
		int v = vert[A][B] - vert[a][B] - vert[A][b-1] + vert[a][b-1];
		int h = hori[A][B] - hori[a-1][B] - hori[A][b] + hori[a-1][b];
		cout << g - v - h << '\n';
	}

	return 0;
}
