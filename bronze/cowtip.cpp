#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector<vector<int>> jar(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c; cin >> c;
			jar[i][j] = int(c-'0');
		}
	}

	//for (auto &row : jar) {
	//	for (auto &e : row) cout << e;
	//	cout << endl;
	//}

	return 0;
}
