#include <bits/stdc++.h>
using namespace std;

struct Event {
	int q, u, v, n;
	bool operator<(const Event &other) const {
		if (u == other.u) return v < other.v;
		else return u < other.u;
	}
};

int main() {
	int N; cin >> N;
	vector<Event> events(N);
	for (int i = 0; i < N; i++) {
		int q, t, x, n;
		cin >> q >> t >> x >> n;
		events[i] = {q, t+x, t-x, n};
	}
	sort(begin(events), end(events));

	int apples = 0;
	map<int, int, greater<int>> cnt;

	for (auto &ev : events) {
		if (ev.q == 1) {
			cnt[ev.v] += ev.n;
		} else {
			auto it = cnt.lower_bound(ev.v);
			while (it != cnt.end() && ev.n > 0) {
				int tmp = min(ev.n, it->second);
				it->second -= tmp;
				ev.n -= tmp;
				apples += tmp;

				if (!it->second) it = cnt.erase(it);
			}
		}
	}

	cout << apples << endl;
	return 0;
}
