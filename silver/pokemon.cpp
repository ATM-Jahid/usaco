#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<char> jar(n);
	set<char> fullset;
	for (auto &x : jar) {
		cin >> x;
		fullset.insert(x);
	}
	int S = fullset.size();

	set<char> occset;
	map<char, int> counts;
	int shortest = n, right = 0;
	for (int i = 0; i < n; i++) {
		while (right < n && occset.size() < S) {
			occset.insert(jar[right]);
			counts[jar[right]]++;
			right++;
		}
		if (occset.size() == S) shortest = min(shortest, right - i);

		counts[jar[i]]--;
		if (counts[jar[i]] == 0) occset.erase(jar[i]);
	}
	cout << shortest << endl;

	return 0;
}
