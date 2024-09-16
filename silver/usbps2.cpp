#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, m;
	cin >> a >> b >> c >> m;
	vector<int> usb, ps2;
	for (int i = 0; i < m; i++) {
		int v; string s;
		cin >> v >> s;
		if (s == "USB") usb.push_back(v);
		else if (s == "PS/2") ps2.push_back(v);
		else return -1;
	}
	sort(begin(usb), end(usb));
	sort(begin(ps2), end(ps2));

	int cnt = 0;
	int filled_a = min(a, int(usb.size()));
	int filled_b = min(b, int(ps2.size()));
	cnt = filled_a + filled_b;

	long long cost = 0;
	for (int i = 0; i < filled_a; i++) cost += usb[i];
	for (int i = 0; i < filled_b; i++) cost += ps2[i];

	vector<int> rem;
	for (int i = filled_a; i < usb.size(); i++) rem.push_back(usb[i]);
	for (int i = filled_b; i < ps2.size(); i++) rem.push_back(ps2[i]);
	sort(begin(rem), end(rem));

	int filled_c = min(c, int(rem.size()));
	cnt += filled_c;
	for (int i = 0; i < filled_c; i++) cost += rem[i];

	cout << cnt << ' ' << cost << endl;
	return 0;
}
