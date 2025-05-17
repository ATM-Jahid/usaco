#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Event {
	int t;
	int x;
	int y;

	bool operator<(const Event &other) const {
		if (t == other.t) {
			if (x == other.x) return y < other.y;
			else return x < other.x;
		}
		else return t < other.t;
	}
};

bool reachable(Event a, Event b) {
	ll dt = abs(a.t - b.t) * 1LL;
	ll dx = abs(a.x - b.x) * 1LL;
	ll dy = abs(a.y - b.y) * 1LL;

	if (dt * dt >= dx * dx + dy * dy) return true;
	else return false;
}

int main() {
	int G, N; cin >> G >> N;
	vector<Event> grazings;
	for (int i = 0; i < G; i++) {
		int x, y, t; cin >> x >> y >> t;
		grazings.push_back({t, x, y});
	}
	sort(begin(grazings), end(grazings));

	int innocents = 0;
	for (int i = 0; i < N; i++) {
		int x, y, t; cin >> x >> y >> t;
		Event alibi {t, x, y};

		int gi = distance(begin(grazings),
				upper_bound(begin(grazings), end(grazings), alibi));

		bool possible = true;
		if (gi && !reachable(alibi, grazings[gi-1])) possible = false;
		if (gi < G && !reachable(alibi, grazings[gi])) possible = false;

		if (!possible) innocents++;
	}

	cout << innocents << '\n';
	return 0;
}
