#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("herding.in");
	ofstream fout("herding.out");

	int N; fin >> N;
	vector<int> jar(N);
	for (auto &x : jar) fin >> x;
	sort(begin(jar), end(jar));

	int l = 0, r = 1, minMoves = INT_MAX;
	while (r < N) {
		if (jar[r] - jar[l] + 1 < N) {
			r++;
		} else if (jar[r] - jar[l] + 1 == N) {
			minMoves = min(minMoves, N - (r - l + 1));
			l++;
			r++;
		} else if (jar[r] - jar[l] + 1 > N) {
			if (l != 0 || r != N-1) {
				minMoves = min(minMoves, N - (r - l));
			} else {
				minMoves = min(minMoves, N - (r - l - 1));
			}
			l++;
		}
	}

	r = N-1, l = N-2;
	while (l >= 0) {
		if (jar[r] - jar[l] + 1 < N) {
			l--;
		} else if (jar[r] - jar[l] + 1 == N) {
			minMoves = min(minMoves, N - (r - l + 1));
			l--;
			r--;
		} else if (jar[r] - jar[l] + 1 > N) {
			if (l != 0 || r != N-1) {
				minMoves = min(minMoves, N - (r - l));
			} else {
				minMoves = min(minMoves, N - (r - l - 1));
			}
			r--;
		}
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
