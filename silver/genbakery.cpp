#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
	srand(atoi(argv[1]));

	cout << "1\n";

	int n = 10, mod = 10;
	cout << n << ' ' << 1 + rand() % mod << ' ' << 1 + rand() % mod << endl;

	for (int i = 0; i < n; i++) {
		int a = 1 + rand() % mod, b = 1 + rand() % mod;
		// ll c = a + b + 1LL * rand() * rand();
		int c = a + b + rand() % mod;
		cout << a << ' ' << b << ' ' << c << endl;
	}

	return 0;
}
