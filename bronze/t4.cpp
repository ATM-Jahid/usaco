#include <bits/stdc++.h>
using namespace std;

void check(string s, vector<set<set<char>>> &box) {
	set<char> tmp;
	for (int i = 0; i < 3; i++) tmp.insert(s[i]);
	box[tmp.size()].insert(tmp);
}

int main() {
	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);

	vector<char> jar(9);
	for (auto &el : jar) cin >> el;

	vector<set<set<char>>> winners(4);
	for (int i = 0; i < 3; i++) {
		string a{jar[i], jar[i+3], jar[i+6]};
		string b{jar[3*i], jar[3*i+1], jar[3*i+2]};
		check(a, winners);
		check(b, winners);
	}
	string d1{jar[0], jar[4], jar[8]}, d2{jar[2], jar[4], jar[6]};
	check(d1, winners);
	check(d2, winners);

	cout << winners[1].size() << '\n' << winners[2].size() << '\n';
	return 0;
}
