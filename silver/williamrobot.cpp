#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	priority_queue<int, vector<int>, greater<int>> heap;
	for (int i = 0; i < n; i += 2) {
		heap.push(a[i]);
		heap.push(a[i+1]);
		heap.pop();
	}

	long long sum = 0;
	while (!heap.empty()) {
		sum += heap.top();
		heap.pop();
	}
	cout << sum << endl;

	return 0;
}
