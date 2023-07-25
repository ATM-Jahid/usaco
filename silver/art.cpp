#include <bits/stdc++.h>
using namespace std;

int canvas[1001][1001], visited[1001][1001];

int main() {
	ifstream fin("art.in");
	ofstream fout("art.out");

	int N; fin >> N;
	vector<int> a(N*N+1, N+1), b(N*N+1, N+1),
		A(N*N+1), B(N*N+1), rej(N*N+1);
	set<int> visible;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x; fin >> x;
			if (x) visible.insert(x);
			canvas[i+1][j+1] = x;
			a[x] = min(a[x], i+1);
			b[x] = min(b[x], j+1);
			A[x] = max(A[x], i+1);
			B[x] = max(B[x], j+1);
		}
	}

	if (visible.size() == 1) {
		fout << N*N - 1 << '\n';
		return 0;
	}

	// The following block contains a logical bug.
	// It fails test #7 but I don't know why!
	for (int row = 1; row <= N; row++) {
		for (int col = 1; col <= N; col++) {
			int curr = canvas[row][col];
			if (!visited[row][col] && curr) {
				for (int i = a[curr]; i <= A[curr]; i++) {
					for (int j = b[curr]; j <= B[curr]; j++) {
						visited[i][j] = 1;
						if (canvas[i][j] != curr) {
							rej[canvas[i][j]] = 1;
						}
					}
				}
			}
		}
	}

	int possible = 0;
	for (int i = 1; i <= N*N; i++) {
		if (rej[i] == 0) possible++;
	}
	fout << possible << endl;

	return 0;
}
