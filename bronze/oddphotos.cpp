#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	int odds = 0, evens = 0;
	for (int i = 0; i < N; i++) {
		int t; cin >> t;
		if (t % 2) odds++;
		else evens++;
	}

	if (evens > odds) {
		cout << 2 * odds + 1 << '\n';
	} else if ((odds - evens) % 3 == 0) {
		cout << 2 * evens + (odds - evens) / 3 * 2 << '\n';
	} else if ((odds - evens) % 3 == 1) {          
		cout << 2 * evens + (odds - evens) / 3 * 2 - 1 << '\n';
	} else if ((odds - evens) % 3 == 2) {          
		cout << 2 * evens + (odds - evens) / 3 * 2 + 1 << '\n';
	}

	return 0;
}
