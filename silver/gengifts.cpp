#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	srand(atoi(argv[1]));

	int n = 3;
	cout << "1\n" << n << "\n";
	for (int i = 0; i < n; i++) {
		cout << rand() % 10 << ' ' << rand() % 10 << endl;
	}

	return 0;
}
