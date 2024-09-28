#include <bits/stdc++.h>
using namespace std;

int first_true(int lo, int hi, function<bool(int)> fn) {
	for (int dif = hi - lo; dif > 0; dif /= 2) {
		while (lo + dif <= hi && !fn(lo + dif)) {
			lo += dif;
		}
	}
	return lo + 1;
}

int main() {
	ifstream fin("convention.in");
	ofstream fout("convention.out");

	int N, M, C; fin >> N >> M >> C;
	vector<int> time(N);
	for (auto &x : time) fin >> x;
	sort(begin(time), end(time));

	fout << first_true(0, time[N-1]-time[0], [&](int w) {
		int bus_avail = M,
			curr_cow = 0, mvp;

		while (bus_avail--) {
			mvp = curr_cow;
			while (time[mvp] - time[curr_cow] <= w
					&& mvp - curr_cow + 1 <= C
					&& mvp < N) {
				mvp++;
			}
			curr_cow = mvp;
		}

		return mvp == N;
	}) << endl;

	return 0;
}
