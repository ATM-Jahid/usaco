#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);

	int n; cin >> n;
	vector<string> cond(n);
	vector<int> low(n), high(n);
	for (int i = 0; i < n; i++) {
		cin >> cond[i] >> low[i] >> high[i];
	}

	int firno;
	for (int i = 0; i < n; i++) {
		if (cond[i] == "none") {
			firno = i;
			break;
		}
	}

	int down2 = 0, up2 = 1000;
	for (int i = firno; i < n; i++) {
		if (cond[i] == "none") {
			up2 = min(up2, high[i]);
			down2 = max(down2, low[i]);
		} else if (cond[i] == "on") {
			up2 += high[i];
			down2 += low[i];
		} else if (cond[i] == "off") {
			up2 -= low[i];
			down2 -= high[i];
			down2 = max(0, down2);
		}
	}

	int lasno;
	for (int i = n-1; i > -1; i--) {
		if (cond[i] == "none") {
			lasno = i;
			break;
		}
	}

	int down1 = 0, up1 = 1000;
	for (int i = lasno; i > -1; i--) {
		if (cond[i] == "none") {
			up1 = min(up1, high[i]);
			down1 = max(down1, low[i]);
		} else if (cond[i] == "off") {
			up1 += high[i];
			down1 += low[i];
		} else if (cond[i] == "on") {
			up1 -= low[i];
			down1 -= high[i];
			down1 = max(0, down1);
		}
	}

	cout << down1 << ' ' << up1 << '\n';
	cout << down2 << ' ' << up2 << '\n';
	return 0;
}
