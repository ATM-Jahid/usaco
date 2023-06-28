#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N; cin >> N;
	vector<int> A(N), B(N), C(N);
	for (auto &x : A) cin >> x;
	for (auto &x : B) cin >> x;
	for (auto &x : C) cin >> x;

	vector<int> occ(N);
	for (int i = 0; i < N; i++) {
		occ[B[C[i]-1]-1]++;
	}

	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += 1LL * occ[A[i]-1];
	}

	cout << ans << '\n';
	return 0;
}
