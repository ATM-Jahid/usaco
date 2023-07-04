#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream cin("hoofball.in");
	ofstream cout("hoofball.out");

	int N; cin >> N;
	vector<int> jar(N);
	for (auto &x : jar) cin >> x;
	sort(begin(jar), end(jar));
	//for (auto &x : jar) cout << x << ' ';
	//cout << endl;

	vector<int> changes(N);
	changes[0] = 1;
	changes[N-1] = -1;
	for (int i = 1; i < N-1; i++) {
		if (jar[i] - jar[i-1] > jar[i+1] - jar[i]) {
			changes[i] = 1;
		} else {
			changes[i] = -1;
		}
	}
	//for (auto &x : changes) cout << x << ' ';
	//cout << endl;

	int cnt = 0;
	for (int i = 0; i < N-1; i++) {
		if (changes[i] == 1 && changes[i+1] == -1) {
			int tails = 0;
			if (i > 0 && changes[i-1] == 1) tails++;
			if (i < N-2 && changes[i+2] == -1) tails++;
			//cout << i << ' ' << tails << endl;
			if (tails == 2) cnt += 2;
			else cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}
