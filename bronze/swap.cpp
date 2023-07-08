#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("swap.in");
	ofstream fout("swap.out");

	int N, K; fin >> N >> K;
	vector<int> path[N+1];
	int a1, a2; fin >> a1 >> a2;
	int b1, b2; fin >> b1 >> b2;

	for (int i = 1; i <= N; i++) {
		int curr = i;
		do {
			if (a1 <= curr && curr <= a2) {
				curr = a2 - (curr - a1);
			}
			if (b1 <= curr && curr <= b2) {
				curr = b2 - (curr - b1);
			}
			path[i].push_back(curr);
		} while (curr != i);
	}

	vector<int> aft(N+1);
	for (int i = 1; i <= N; i++) {
		int l = path[i].size();
		if (l > 0 && K % l) {
			aft[path[i][K % l - 1]] = i;
		} else aft[i] = i;
	}

	for (int i = 1; i <= N; i++) fout << aft[i] << '\n';
	
	return 0;
}
