#include <bits/stdc++.h>
using namespace std;

int arr[50][50] = {};
int N, M, K;

int putt(int i, int j, int num) {
	if (i >= 0 && i < N && j >= 0 && j < M) {
		if (arr[i][j] == 0 || num < arr[i][j]) {
			arr[i][j] = num;
		}
	}
	return 0;
}

int main() {
	cin >> N >> M >> K;
	vector<int> xs(K), ys(K), ts(K);
	for (int i = 0; i < K; i++) {
		cin >> xs[i] >> ys[i] >> ts[i];
	}

	for (int k = 0; k < K; k++) {
		int d = 0, t = (ts[k] == 0 ? 1 : -1);
		int i = xs[k]-1, j = ys[k]-1, num = 1;
		arr[i][j] = num;

		for (int it = 0; it < max(N, M); it++) {
			d++;
			for (int l = 0; l < d; l++) {
				i--; num++;
				putt(i, j, num);
			}
			for (int l = 0; l < d; l++) {
				j+=t; num++;
				putt(i, j, num);
			}
			d++;
			for (int l = 0; l < d; l++) {
				i++; num++;
				putt(i, j, num);
			}
			for (int l = 0; l < d; l++) {
				j-=t; num++;
				putt(i, j, num);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
