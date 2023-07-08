#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("family.in");
	ofstream fout("family.out");

	int N; fin >> N;
	string cow1, cow2; fin >> cow1 >> cow2;
	map<string, string> mom;
	for (int i = 0; i < N; i++) {
		string a, b; fin >> a >> b;
		mom[b] = a;
	}

	string anc1 = cow1, anc2 = cow2;
	int lev1 = 0, lev2 = 0;
	while (mom.count(anc1)) {
		lev1++;
		anc1 = mom[anc1];
	}
	while (mom.count(anc2)) {
		lev2++;
		anc2 = mom[anc2];
	}

	if (anc1 != anc2) {
		fout << "NOT RELATED\n";
		return 0;
	}
	if (lev1 == lev2 && mom[cow1] == mom[cow2]) {
		fout << "SIBLINGS\n";
		return 0;
	}

	int diff = abs(lev1 - lev2);
	string old, young;
	if (lev1 > lev2) {
		old = cow2;
		young = cow1;
	} else {
		old = cow1;
		young = cow2;
	}
	
	string dirAnc = young;
	for (int i = 0; i < diff; i++) {
		dirAnc = mom[dirAnc];
	}
	if (dirAnc == old) {
		string rel;
		if (diff == 1) {
			rel = "mother";
		} else if (diff == 2) {
			rel = "grand-mother";
		} else {
			for (int j = 0; j < diff-2; j++) {
				rel += "great-";
			}
			rel += "grand-mother";
		}
		fout << old << " is the " << rel << " of " << young << '\n';
	} else if (mom[dirAnc] == mom[old]) {
		string rel;
		if (diff == 1) {
			rel = "aunt";
		} else {
			for (int j = 0; j < diff-1; j++) {
				rel += "great-";
			}
			rel += "aunt";
		}
		fout << old << " is the " << rel << " of " << young << '\n';
	} else {
		fout << "COUSINS\n";
	}

	return 0;
}
