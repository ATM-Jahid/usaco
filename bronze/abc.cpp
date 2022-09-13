#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> jar(7);
	for (auto &x : jar) cin >> x;

	sort(jar.begin(), jar.end());
	int a = jar[0];
	int b = jar[1];
	int c = jar[6] - a - b;

	cout << a << ' ' << b << ' ' << c << '\n';
	return 0;
}
