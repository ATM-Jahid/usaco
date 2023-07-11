#include <bits/stdc++.h>
using namespace std;

int process(vector<int> &foo) {
	int len = foo.size();

	if (len == 0) {
		cout << "0\n";
	} else if (len == 1) {
		cout << "pushStack\n1 popStack\n";
	} else if (len == 2) {
		cout << "pushStack\npushQueue\n2 popStack popQueue\n";
	} else if (len == 3) {
		cout << "pushStack\npushQueue\npushFront\n3 popStack popQueue popFront\n";
	} else {
		vector<int> bar = foo;
		sort(begin(bar), end(bar), [](auto &l, auto &r) {return l > r;});

		vector<int> a(3, -1);
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < 3; j++) {
				if (a[j] == -1 && foo[i] == bar[j]) {
					a[j] = i;
					break;
				}
			}
		}
		sort(begin(a), end(a));

		for (int i = 0; i < a[0]; i++) cout << "pushStack\n";
		cout << "pushQueue\n";
		for (int i = a[0]+1; i < a[1]; i++) cout << "pushStack\n";
		cout << "pushFront\n";
		for (int i = a[1]+1; i <= a[2]; i++) cout << "pushStack\n";
		for (int i = a[2]+1; i < len; i++) cout << "pushBack\n";
		cout << "3 popStack popQueue popFront\n";
	}

	return 0;
}

int main() {
	int n; cin >> n;
	vector<int> jar(n);
	for (auto &x : jar) cin >> x;

	int beg = 0;
	for (int i = 0; i < n; i++) {
		if (jar[i] == 0) {
			vector<int> foo = {begin(jar)+beg, begin(jar)+i};
			process(foo);
			beg = i+1;
		}
	}

	for (int i = n-1; i >= 0 && jar[i] != 0; i--) {
		cout << "pushStack\n";
	}

	return 0;
}
