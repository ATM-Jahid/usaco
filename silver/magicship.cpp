#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll first_true(ll lo, ll hi, function<bool(ll)> fn) {
	for (ll dif = hi - lo; dif > 0; dif /= 2) {
		while (lo + dif <= hi && !fn(lo + dif)) lo += dif;
	}
	return lo + 1;
}

int main() {
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n; cin >> n;
	string s; cin >> s;

	ll res = first_true(0LL, (ll)1e15, [&](ll guess) {
		ll dx = x2 - x1, dy = y2 - y1;

		for (int i = 0; i < n; i++) {
			if (s[i] == 'L') {
				dx += (guess / n) + (i < (guess % n));
			} else if (s[i] == 'R') {
				dx -= (guess / n) + (i < (guess % n));
			} else if (s[i] == 'U') {
				dy -= (guess / n) + (i < (guess % n));
			} else if (s[i] == 'D') {
				dy += (guess / n) + (i < (guess % n));
			}
		}

		if (abs(dx) + abs(dy) > guess) return false;
		else return true;
	});

	if (res > (ll)1e15) cout << "-1\n";
	else cout << res << '\n';

	return 0;
}
