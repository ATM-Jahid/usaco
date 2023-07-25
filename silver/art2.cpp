#include <bits/stdc++.h>
using namespace std;

int canvas[1002][1002], occ[1002][1002];

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
			a[x] = min(a[x], i+1); A[x] = max(A[x], i+1);
			b[x] = min(b[x], j+1); B[x] = max(B[x], j+1);
		}
	}

	if (visible.size() == 1) {
		fout << N*N - 1 << '\n';
		return 0;
	}

	for (auto &colo : visible) {
		occ[a[colo]][b[colo]]++;
		occ[A[colo]+1][b[colo]]--;
		occ[a[colo]][B[colo]+1]--;
		occ[A[colo]+1][B[colo]+1]++;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			occ[i][j] += occ[i-1][j] + occ[i][j-1] - occ[i-1][j-1];
			if (occ[i][j] > 1) {
				rej[canvas[i][j]] = 1;
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
