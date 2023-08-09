#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("pairup.in");
	ofstream fout("pairup.out");

	int N; fin >> N;
	vector<pair<int, int>> jar(N); // <milking time, #cows>
	for (int i = 0; i < N; i++) {
		fin >> jar[i].second >> jar[i].first;
	}
	sort(begin(jar), end(jar));

	int mint = 0, left = 0, right = N-1;
	while (left <= right) {
		mint = max(mint, jar[left].first + jar[right].first);
		int subt = min(jar[left].second, jar[right].second);
		jar[left].second -= subt;
		if (jar[left].second == 0) left++;
		jar[right].second -= subt;
		if (jar[right].second == 0) right--;
	}
	fout << mint << endl;

	return 0;
}
