#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	int must = 0, fmin = 0, fmax = 0;

	char pref; cin >> pref;
	int fcnt = 0, step = 2;
	if (pref == 'F') fcnt++;

	for (int i = 1; i < N; i++) {
		char c; cin >> c;
		if (fcnt && c == 'F') {
			fcnt++;
		} else if (fcnt && c != 'F') {
			if (pref == 'F') {
				step = 1;
				fmax += fcnt;
			} else if (pref == c) {
				if (fcnt % 2 == 0) fmin++;
				fmax += fcnt + 1;
			} else {
				if (fcnt % 2 == 1) fmin++;
				fmax += fcnt;
			}
			fcnt = 0;
			pref = c;
		} else if (!fcnt && c == 'F') {
			fcnt = 1;
		} else if (!fcnt && c != 'F') {
			if (pref == c) must++;
			pref = c;
		}
	}

	if (fcnt) {
		step = 1;
		if (pref == 'F') {
			fmax = N - 1;
		} else {
			fmax += fcnt;
		}
	}

	cout << (fmax-fmin)/step + 1 << '\n';
	for (int i = must+fmin; i <= must+fmax; i += step) {
		cout << i << '\n';
	}

	return 0;
}
