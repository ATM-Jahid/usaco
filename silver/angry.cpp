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
	ifstream fin("angry.in");
	ofstream fout("angry.out");

	int N, K; fin >> N >> K;
	vector<int> x(N);
	for (auto &el : x) fin >> el;
	sort(begin(x), end(x));
	
	fout << first_true(1, x[N-1]-x[0], [&](int R) {
		int cows = K,
			drop = x[0];
		bool succ = false;

		while (cows) {
			cows--;
			auto it = upper_bound(begin(x), end(x), drop + 2 * R);
			if (it == end(x)) {
				succ = true;
				break;
			}
			drop = *it;
		}

		return succ;
	}) << endl;

	return 0;
}
