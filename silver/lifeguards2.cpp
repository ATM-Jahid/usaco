#include <bits/stdc++.h>
using namespace std;

struct Event {
	int time;
	int id;
	bool is_start;
};

bool operator<(const Event &a, const Event &b) {
	return a.time < b.time;
}

int main() {
	ifstream fin("lifeguards.in");
	ofstream fout("lifeguards.out");

	int N; fin >> N;
	vector<Event> events;
	for (int i = 0; i < N; i++) {
		int a, b; fin >> a >> b;
		events.push_back({a, i, true});
		events.push_back({b, i, false});
	}
	sort(begin(events), end(events));

	set<int> active;
	vector<int> lonely(N);
	int prev_time = 0, total_time = 0;

	for (auto &e : events) {
		int curr_time = e.time;

		if (active.size() > 0) {
			total_time += curr_time - prev_time;
		}
		if (active.size() == 1) {
			lonely[*begin(active)] += curr_time - prev_time;
		}

		if (e.is_start) {
			active.insert(e.id);
		} else {
			active.erase(e.id);
		}
		prev_time = curr_time;
	}

	int min_time = *min_element(begin(lonely), end(lonely));
	fout << total_time - min_time << endl;

	return 0;
}
