#include <bits/stdc++.h>
using namespace std;

struct Event {
	int time;
	int person;
	int milk;
};

int main() {
	ifstream fin("badmilk.in");
	ofstream fout("badmilk.out");

	int N, M, D, S; fin >> N >> M >> D >> S;
	vector<Event> events;
	for (int i = 0; i < D; i++) {
		int p, m, t; fin >> p >> m >> t;
		events.push_back({t, p, m});
	}
	for (int i = 0; i < S; i++) {
		int p, t; fin >> p >> t;
		events.push_back({t, p, -1});
	}

	sort(events.begin(), events.end(), [] (auto &e1, auto &e2) {
		return e1.time != e2.time ? e1.time < e2.time : e1.milk < e2.milk;
	});

	int meds = 0;
	for (int m = 1; m < M+1; m++) {
		int bad = 1;
		vector<int> sick(N+1);
		for (auto ev : events) {
			if (ev.milk == m) {
				sick[ev.person] = 1;
			} else if (ev.milk == -1) {
				if(sick[ev.person] == 0) {
					bad = 0;
					break;
				}
			}
		}
		if (bad) {
			int run = 0;
			for (auto el : sick) run += el;
			meds = max(meds, run);
		}
	}

	fout << meds << '\n';
	return 0;
}
