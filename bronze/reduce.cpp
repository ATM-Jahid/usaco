#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("reduce.in");
	ofstream fout("reduce.out");

	int N; fin >> N;
	vector<pair<int, int>> jar(N);
	for (auto &j : jar) {
		int x, y; fin >> x >> y;
		j.first = x;
		j.second = y;
	}

	set<pair<int, int>> reduced;

	sort(begin(jar), end(jar));
	for (int i = 0; i < 4; i++) {
		reduced.insert({jar[i].first, jar[i].second});
		reduced.insert({jar[N-1-i].first, jar[N-1-i].second});
	}

	sort(begin(jar), end(jar), [](auto &left, auto &right){
			return left.second < right.second;
	});
	for (int i = 0; i < 4; i++) {
		reduced.insert({jar[i].first, jar[i].second});
		reduced.insert({jar[N-1-i].first, jar[N-1-i].second});
	}

	vector<pair<int, int>> red(begin(reduced), end(reduced));
	int L = red.size();

	int area = INT_MAX;
	for (int i = 0; i < L; i++) {
		for (int j = i+1; j < L; j++) {
			for (int k = j+1; k < L; k++) {
				set<pair<int, int>> locReduced = reduced;
				locReduced.erase(red[i]);
				locReduced.erase(red[j]);
				locReduced.erase(red[k]);
				vector<pair<int, int>> locRed(begin(locReduced), end(locReduced));
				sort(begin(locRed), end(locRed));
				int xd = abs(locRed[0].first - locRed[locRed.size()-1].first);
				sort(begin(locRed), end(locRed), [](auto &l, auto &r) {return l.second < r.second;});
				int yd = abs(locRed[0].second - locRed[locRed.size()-1].second);
				area = min(area, xd * yd);
			}
		}
	}

	fout << area << '\n';
	return 0;
}
