#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int> jar(N);
	for (auto &x : jar) cin >> x;

	vector<int> forward(N), backward(N);
	forward[0] = jar[0];
	for (int i = 1; i < N; i++) {
		forward[i] = gcd(forward[i-1], jar[i]);
	}
	backward[N-1] = jar[N-1];
	for (int i = N-2; i >= 0; i--) {
		backward[i] = gcd(backward[i+1], jar[i]);
	}

	int ans = 0;
	ans = max(ans, backward[1]);
	for (int i = 1; i < N-1; i++) {
		ans = max(ans, gcd(forward[i-1], backward[i+1]));
	}
	ans = max(ans, forward[N-2]);
	cout << ans << '\n';

	return 0;
}
