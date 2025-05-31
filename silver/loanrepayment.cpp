#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ifstream fin("loan.in");
	ofstream fout("loan.out");

	ll N, K, M;
	fin >> N >> K >> M;

	auto works = [&](ll X) {
		ll G = 0LL, Y, days = 0LL;

		while (G < N && days < K) {
			Y = (N - G) / X;
			if (Y < M) {
				G += M * (K - days);
				break;
			}

			ll more_at_y = (N - X * Y) - G;
			ll days_at_y = more_at_y / Y + 1;
			if (days + days_at_y > K) {
				days_at_y = K - days;
			}

			G += days_at_y * Y;
			days += days_at_y;
		}

		return G >= N;
	};

	ll lo = 1LL, hi = N;
	while (lo < hi) {
		ll mid = lo + (hi - lo + 1) / 2;
		if (works(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	fout << lo << endl;

	return 0;
}
