#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);

	vector<int> c(3), m(3);
	for (int i = 0; i < 3; i++) cin >> c[i] >> m[i];

	int carry;
	for (int i = 0; i < 100; i++) {
		carry = min(c[(i+1)%3]-m[(i+1)%3], m[i%3]);
		m[i%3] -= carry;
		m[(i+1)%3] += carry;
	}

	for (int i = 0; i < 3; i++) cout << m[i] << '\n';
	return 0;
}
