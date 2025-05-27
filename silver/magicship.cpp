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

	vector<int> pdx(n+1), pdy(n+1);
	for (int i = 1; i <= n; i++) {
		pdx[i] = pdx[i-1];
		pdy[i] = pdy[i-1];

		char c = s[i-1];
		if (c == 'L') pdx[i]++;
		else if (c == 'R') pdx[i]--;
		else if (c == 'U') pdy[i]--;
		else if (c == 'D') pdy[i]++;
		else return -1;
	}

	ll res = first_true(0LL, (ll)1e15, [&](ll guess) {
		ll dx = x2 - x1, dy = y2 - y1;
		ll quo = guess / n, rem = guess % n;

		dx += pdx[n] * quo + pdx[rem];
		dy += pdy[n] * quo + pdy[rem];

		if (abs(dx) + abs(dy) > guess) return false;
		else return true;
	});

	if (res > (ll)1e15) cout << "-1\n";
	else cout << res << '\n';

	return 0;
}
