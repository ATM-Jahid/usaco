#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);

	int n; cin >> n;
	vector<int> b(101), m(101), e(101);

	int day, amt; string cow;
	for (int i = 0; i < n; i++) {
		cin >> day >> cow >> amt;
		if (cow == "Bessie") b[day] += amt;
		else if (cow == "Mildred") m[day] += amt;
		else if (cow == "Elsie") e[day] += amt;
		else return -1;
	}

	int bes = 0, mil = 0, els = 0, ans = 0;
	set<char> curr = {'b', 'm', 'e'}, newc;
	for (int i = 1; i < 101; i++) {
		if (b[i]) bes += b[i];
		else if (m[i]) mil += m[i];
		else if (e[i]) els += e[i];
		int most = max({bes, mil, els});
		if (bes == most) newc.insert('b');
		if (mil == most) newc.insert('m');
		if (els == most) newc.insert('e');
		if (newc != curr) {
			ans++;
			curr = newc;
		}
		newc.clear();
	}

	cout << ans << '\n';
	return 0;
}
