#include <bits/stdc++.h>
using namespace std;

int main() {
	map<pair<int, int>, int> jar;
	int x, y;
	cin >> x >> y;
	cout << jar.count({x, y}) << '\n';
	jar[{0, 0}] = 0;
	cout << jar.count({x, y}) << '\n';

	return 0;
}
