#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	srand(atoi(argv[1]));

	int n = 1000;
	cout << n << '\n';
	for (int i = 0; i < n; i++) {
		cout << rand() % 1000 + 1 << ' ';
	}
	cout << endl;

	return 0;
}
