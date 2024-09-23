#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	srand(atoi(argv[1]));

	set<int> jar;
	while (jar.size() < 10) {
		int t = rand() % 20;
		jar.insert(t);
	}
	cout << "7 3 3\n";
	auto it = next(jar.begin(), rand() % 5);
	int n1 = *it; jar.erase(it);
	it = next(jar.begin(), rand() % 5);
	int n2 = *it; jar.erase(it);
	it = next(jar.begin(), rand() % 5);
	int n3 = *it; jar.erase(it);
	for (auto &x : jar) {
		cout << x << ' ' << rand() % 10 << endl;
	}
	cout << n1 << endl;
	cout << n2 << endl;
	cout << n3 << endl;

	return 0;
}
