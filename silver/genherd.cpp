#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	srand(atoi(argv[1]));

	set<int> jar;
	for (int i = 0; i < 10; i++) {
		int num = rand() % 20;
		jar.insert(num);
	}

	cout << jar.size() << endl;
	for (auto &x : jar) cout << x << endl;

	return 0;
}
