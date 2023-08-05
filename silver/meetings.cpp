#include <bits/stdc++.h>
using namespace std;

struct Cow {
	int x, dir, wt, dst;
	bool operator<(const Cow &other) const {
		return x < other.x;
	}
};

int main() {
	ifstream fin("meetings.in");
	ofstream fout("meetings.out");

	int N, L, totWt = 0;
	fin >> N >> L;
	vector<Cow> cows(N);
	for (auto &c : cows) {
		fin >> c.wt >> c.x >> c.dir;
		totWt += c.wt;
		if (c.dir == 1) c.dst = L - c.x;
		else c.dst = c.x;
	}
	sort(begin(cows), end(cows));

	vector<int> weights(N);
	for (int i = 0; i < N; i++) {
		weights[i] = cows[i].wt;
	}
	int cur = 0;
	for (int i = 0; i < N; i++) {
		if (cows[i].dir == -1) {
			cows[i].wt = weights[cur];
			cur++;
		}
	}
	for (int i = 0; i < N; i++) {
		if (cows[i].dir == 1) {
			cows[i].wt = weights[cur];
			cur++;
		}
	}

	sort(begin(cows), end(cows), [](auto &l, auto &r) {
		return l.dst < r.dst;
	});
	int curWt = 0, curDst = 0, time;
	for (auto &c : cows) {
		if (c.dst != curDst && 2 * curWt >= totWt) {
			time = curDst;
			break;
		}
		curWt += c.wt;
		curDst = c.dst;
	}

	sort(begin(cows), end(cows));
	vector<int> pref(N);
	for (int i = 0; i < N; i++) {
		pref[i] = (cows[i].dir == -1);
		if (i) pref[i] += pref[i-1];
	}
	int meetings = 0;
	for (int i = 0; i < N; i++) {
		if (cows[i].dir == 1) {
			Cow cEdge = {.x = cows[i].x + 2 * time};
			int d = distance(begin(cows),
					upper_bound(begin(cows), end(cows), cEdge));
			meetings += pref[d-1] - pref[i];
		}
	}
	fout << meetings << endl;

	return 0;
}
