#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("herding.in");
	ofstream fout("herding.out");

	int N; fin >> N;
	vector<int> jar(N);
	for (auto &x : jar) fin >> x;
	sort(begin(jar), end(jar));

	int minMoves;
	if ((jar[N-2] - jar[0] + 1 == N-1 && jar[N-1] - jar[N-2] > 2) ||
		(jar[N-1] - jar[1] + 1 == N-1 && jar[1] - jar[0] > 2)) {
		minMoves = 2;
	} else {
		int r = 0, dense = 0;
		for (int i = 0; i < N; i++) {
			while (r+1 < N && jar[r+1] - jar[i] + 1 <= N) {
				r++;
			}
			dense = max(dense, r - i + 1);
		}
		minMoves = N - dense;
	}

	int dist = 0, maxMoves;
	for (int i = 1; i < N; i++) {
		dist += jar[i] - jar[i-1] - 1;
	}
	maxMoves = max(dist - (jar[1] - jar[0] - 1),
			dist - (jar[N-1] - jar[N-2] - 1));

	fout << minMoves << endl << maxMoves << endl;

	return 0;
}
