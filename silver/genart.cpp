#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int N = 9;
	vector<vector<int>> canvas(N+1, vector<int>(N+1));

	srand(atoi(argv[1]));
	for (int colo = 1; colo <= N*N; colo++) {
		int a, b, A, B;
		a = rand() % 9 + 1; b = a + rand() % (10 - a);
		A = rand() % 9 + 1; B = A + rand() % (10 - A);
		for (int i = a; i <= A; i++) {
			for (int j = b; j <= B; j++) {
				canvas[i][j] = colo;
			}
		}
	}

	cout << N << '\n';
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << canvas[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
