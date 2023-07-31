#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
	ifstream fin("mountains.in");
	ofstream fout("mountains.out");

	int N; fin >> N;
	vector<pii> peaks(N);
	for (int i = 0; i < N; i++) {
		fin >> peaks[i].first >> peaks[i].second;
	}
	sort(begin(peaks), end(peaks));

	vector<pii> red;
	for (int i = 0; i < N; i++) {
		if (i == 0 || peaks[i].first > peaks[i-1].first) {
			red.push_back(peaks[i]);
		} else {
			red.back().second = peaks[i].second;
		}
	}

	int L = red.size();
	if (L == 1) {
		fout << "1\n";
		return 0;
	}

	vector<int> prefix(L), suffix(L);
	prefix[0] = red[0].first + red[0].second;
	for (int i = 1; i < L; i++) {
		prefix[i] = max(prefix[i-1], red[i].first + red[i].second);
	}
	suffix[L-1] = red[L-1].first - red[L-1].second;
	for (int i = L-2; i >= 0; i--) {
		suffix[i] = min(suffix[i+1], red[i].first - red[i].second);
	}

	int visible = 0;
	if (red[0].first - red[0].second < suffix[1]) {
		visible++;
	}
	if (red[L-1].first + red[L-1].second > prefix[L-2]) {
		visible++;
	}
	for (int i = 1; i < L-1; i++) {
		if (red[i].first + red[i].second > prefix[i-1] &&
				red[i].first - red[i].second < suffix[i+1]) {
			visible++;
		}
	}
	fout << visible << endl;

	return 0;
}
