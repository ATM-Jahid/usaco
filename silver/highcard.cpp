#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("highcard.in");
	ofstream fout("highcard.out");

	int n; fin >> n;
	vector<bool> elsie(2*n+1);
	for (int i = 0; i < n; i++) {
		int t; fin >> t;
		elsie[t] = 1;
	}

	int wins = 0, highcards = 0;
	for (int i = 2*n; i > 0; i--) {
		if (elsie[i]) {
			if (highcards) {
				wins++;
				highcards--;
			}
		} else {
			highcards++;
		}
	}

	fout << wins << endl;
	return 0;
}
