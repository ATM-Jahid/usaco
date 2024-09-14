#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		pq.push(tmp);
	}

	long long ans = 0;
	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		ans += a + b;
		pq.push(a + b);
	}

	cout << ans << endl;
	return 0;
}
