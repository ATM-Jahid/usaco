#include <bits/stdc++.h>
using namespace std;

int first_true(int lo, int hi, function<bool(int)> fn) {
	for (int dif = hi - lo; dif > 0; dif /= 2) {
		while (lo + dif <= hi && !fn(lo + dif)) {
			lo += dif;
		}
	}
	return lo + 1;
}

int main() {
	ifstream fin("cowdance.in");
	ofstream fout("cowdance.out");

	int N, Tmax;
	fin >> N >> Tmax;
	vector<int> d(N);
	for (auto &x : d) fin >> x;

	fout << first_true(1, N, [&](int k) {
		priority_queue<int> pq;
		for (int i = 0; i < k; i++) pq.push(-d[i]);

		int time;
		for (int i = k; i < N; i++) {
			time = -pq.top();
			pq.pop();
			pq.push(-(time + d[i]));
		}

		while (!pq.empty()) {
			time = -pq.top();
			pq.pop();
		}

		return time <= Tmax;
	}) << endl;

	return 0;
}
