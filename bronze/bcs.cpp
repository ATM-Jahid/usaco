#include <bits/stdc++.h>
using namespace std;

vector<int> convert(vector<char> fig, int N) {
	vector<int> nufig(N*N);

	for (int i = 0; i < N*N; i++) {
		if (fig[i] == '#') {
			nufig[i] = 1;
		} else if (fig[i] == '.') {
			nufig[i] = 0;
		}
	}

	return nufig;
}

vector<int> shift(vector<int> figur, int N) {
	int top = N, left = N;
	vector<int> shifted(N*N);

	for (int i = 0; i < N*N; i++) {
		if (figur[i] == 1) {
			top = min(top, i / N);
			left = min(left, i % N);
		}
	}
	
	for (int i = top; i < N; i++) {
		for (int j = left; j < N; j++) {
			if (figur[i*N + j] == 1) {
				shifted[(i-top)*N + (j-left)] = 1;
			}
		}
	}

	return shifted;
}

vector<int> subtract(vector<int> base, vector<int> comp, int N) {
	for (int i = 0; i < N*N; i++) {
		if (comp[i] == 1) {
			base[i] += 2;
			if (base[i] == 3) {
				base[i] = 0;
			}
		}
	}

	return shift(base, N);
}

int main() {
	ifstream fin("bcs.in");
	ofstream fout("bcs.out");

	int N, K; fin >> N >> K;

	vector<char> figurine(N*N);
	for (int i = 0; i < N*N; i++) {
		fin >> figurine[i];
	}
	vector<int> orig = shift(convert(figurine, N), N);

	vector<vector<char>> broken(K, vector<char>(N*N));
	for (int k = 0; k < K; k++) {
		for (int i = 0; i < N*N; i++) {
			fin >> broken[k][i];
		}
	}

	for (int k = 0; k < K; k++) {
		vector<int> primero = shift(convert(broken[k], N), N);
		for (int l = k+1; l < K; l++) {
			vector<int> segundo = shift(convert(broken[l], N), N);
			vector<int> sub1 = subtract(orig, primero, N);
			vector<int> sub2 = subtract(orig, segundo, N);
			if (sub1 == segundo || sub2 == primero) {
				fout << k+1 << ' ' << l+1 << '\n';
				return 0;
			}
		}
	}

	return -1;
}
