#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve () {
	ll k; cin >> k;

	ll i, dpos = 0;
	for (i = 1; dpos < 1e18; i++) {
		ll cnt = 9;
		for (int j = 1; j < i; j++) cnt *= 10;
		if (dpos + i * cnt < k) {
			dpos += i * cnt;
		} else {
			break;
		}
	}

	ll adv;
	if ((k-dpos) % i) {
		adv = (k-dpos)/i;
	} else {
		adv = (k-dpos)/i - 1;
	}
	dpos += adv * i;

	ll num = pow(10, i-1);
	num += adv;

	cout << to_string(num)[k-dpos-1] << endl;
	return 0;
}

int main() {
	int q; cin >> q;
	while (q--) {
		solve();
	}
	return 0;
}
