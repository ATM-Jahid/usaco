#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

	string jar; cin >> jar;

	int cPairs = 0;
	for (char c = 'A'; c <= 'Z'; c++) {
		auto found = jar.find(c);
		set<char> between;
		for (auto i = found+1; jar[i] != c; i++) {
			if (between.count(jar[i])) between.erase(jar[i]);
			else between.insert(jar[i]);
		}
		cPairs += between.size();
	}

	cout << cPairs / 2 << '\n';
	return 0;
}
