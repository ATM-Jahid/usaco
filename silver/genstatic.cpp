#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	srand(atoi(argv[1]));

	cout << "5 5\n";
	int l, r, v;
	for (int i = 0; i < 5; i++) {
		l = rand() % int(1e2);
		r = l + 1 + rand() % (int(1e2) - l + 1);
		v = rand() % int(1e2);
		cout << l << ' ' << r << ' ' << v << '\n';
	}
	for (int i = 0; i < 5; i++) {
		l = rand() % int(1e2);
		r = l + 1 + rand() % (int(1e2) - l + 1);
		cout << l << ' ' << r << '\n';
	}

	return 0;
}
