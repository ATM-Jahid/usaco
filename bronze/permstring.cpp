#include <bits/stdc++.h>
using namespace std;

set<string> permset;

int permute(int index, int n, vector<char> jar, string foo, vector<int> used) {
	if (index == n) {
		permset.insert(foo);
		return 0;
	}

	for (int i = 0; i < n; i++) {
		int unused = 1;
		for (auto x : used) {
			if (x == i) {
				unused = 0;
				break;
			}
		}
		if (unused) {
			used.push_back(i);
			permute(index+1, n, jar, foo+jar[i], used);
			used.pop_back();
		}
	}

	return 0;
}

int main() {
	vector<char> jar;
	char c;
	while ((c = cin.get()) != '\n') {
		jar.push_back(c);
	}
	int n = jar.size();

	vector<int> empty;
	permute(0, n, jar, "", empty);

	cout << permset.size() << '\n';
	for (auto x : permset) {
		cout << x << '\n';
	}

	return 0;
}
