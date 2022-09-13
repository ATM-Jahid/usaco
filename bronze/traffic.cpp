#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);

	int n; cin >> n;
	vector<string> swi(n);
	vector<int> low(n), high(n);
	for (int i = 0; i < n; i++) {
		cin >> swi[i] >> low[i] >> high[i];
	}

	int bot2 = -1000000, top2 = 1000000;
	for (int i = 0; i < n; i++) {
		if (swi[i] == "none") {
			bot2 = max(bot2, low[i]);
			top2 = min(top2, high[i]);
		} else if ( swi[i] == "on") {
			bot2 += low[i];
			top2 += high[i];
		} else if ( swi[i] == "off") {
			bot2 -= high[i];
			bot2 = max(0, bot2);
			top2 -= low[i];
		}
	}

	int bot1 = -1000000, top1 = 1000000;
	for (int i = n-1; i > -1; i--) {
		if (swi[i] == "none") {
			bot1 = max(bot1, low[i]);
			top1 = min(top1, high[i]);
		} else if ( swi[i] == "off") {
			bot1 += low[i];
			top1 += high[i];
		} else if ( swi[i] == "on") {
			bot1 -= high[i];
			bot1 = max(0, bot1);
			top1 -= low[i];
		}
	}

	cout << bot1 << ' ' << top1 << '\n';
	cout << bot2 << ' ' << top2 << '\n';
	return 0;
}
