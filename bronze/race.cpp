#include <bits/stdc++.h>
using namespace std;

ifstream fin("race.in");
ofstream fout("race.out");

int K;

int solve() {
	int X; fin >> X;

	int adv = 0, time = 0;
	for (int sp = 1; sp < X; sp++) {
		adv += sp;
		time++;
		if (adv >= K) {
			fout << time << '\n';
			return 0;
		}
	}

	for (int sp = X; sp <= 1e5; sp++) {
		for (int i = 0; i < 2; i++) {
			adv += sp;
			time++;
			if (adv >= K) {
				fout << time << '\n';
				return 0;
			}
		}
	}

	return -1;
}

int main() {
	int N; fin >> K >> N;
	while (N--) {
		solve();
	}
	return 0;
}
