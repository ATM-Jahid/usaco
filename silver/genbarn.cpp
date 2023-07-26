#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	srand(atoi(argv[1]));

	int n = 10, k = 2;
	cout << n << ' ' << k << '\n';
	for (int i = 1; i <= n; i++) {
		int a, b, A, B;
		a = rand() % 10 + 180; A = a + rand() % (201 - a);
		b = rand() % 10 + 180; B = b + rand() % (201 - b);
		cout << a << ' ' << b << ' ' << A << ' ' << B << '\n';
	}

	return 0;
}
