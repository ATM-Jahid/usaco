#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	srand(atoi(argv[1]));

	cout << "3 6 3\n";
	for (int i = 0; i < 3; i++) {
		cout << rand() % 10 << ' ';
	}
	cout << endl;
	for (int i = 0; i < 6; i++) {
		cout << rand() % 10 << ' ';
	}
	cout << endl;
	int l, r, v;
	for (int i = 0; i < 3; i++) {
		l = rand() % 3 + 1;
		r = rand() % 3 + 1;
		if (l > r) {
			r = r + l;
			l = r - l;
			r = r - l;
		}
		v = rand() % 10;
		cout << l << ' ' << r << ' ' << v << '\n';
	}

	return 0;
}
