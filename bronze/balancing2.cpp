#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
	ifstream cin("balancing.in");
	ofstream cout("balancing.out");

	int n; cin >> n;
	vector<pii> xsr(n), ysr(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		xsr[i].first = x; xsr[i].second = y;
		ysr[i].second = x; ysr[i].first = y;
	}
	sort(xsr.begin(), xsr.end());
	sort(ysr.begin(), ysr.end());

	int ans = n;
	vector<int> q(4);
	int low = n/3, high = (2*n)/3 + 1;

	int a = xsr[0].first;
	for (int i = low; i < high; i++) {
		if (xsr[i].first == a) continue;
		else {
			q[1] = i; q[0] = n - i;
			q[2] = 0; q[3] = 0;
			int b = ysr[0].first;
			for (int j = 0 ; j < high; j++) {
				if (ysr[j].first == b) {
					if (ysr[j].second <= a) {
						q[1]--;
						q[2]++;
					} else {
						q[0]--;
						q[3]++;
					}
				} else {
					ans = min(ans, *max_element(q.begin(), q.end()));
					b = ysr[j].first; j--;
				}
			}
			a = xsr[i].first;
		}
	}

	cout << ans << '\n';
	return 0;
}
