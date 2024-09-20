#include <bits/stdc++.h>
using namespace std;

struct Project {
	int cap, prof;
	bool operator<(const Project &other) const {
		if (cap == other.cap) return prof < other.prof;
		else return cap < other.cap;
	}
};

class Solution {
public:
    int findMaximizedCapital(int k, int w,
			vector<int> &profits, vector<int> &capital) {

		int n = profits.size();
		vector<Project> projects(n);
		for (int i = 0; i < n; i++) {
			projects[i] = {capital[i], profits[i]};
		}
		sort(begin(projects), end(projects));

		priority_queue<int> pq;
		int total = w, cnt = 0;

		int l = 0;
		while (l < n) {
			if (projects[l].cap > total) {
				if (!pq.empty()) {
					total += pq.top();
					pq.pop();
					cnt++;
				} else break;
			} else {
				pq.push(projects[l].prof);
				l++;
			}

			if (cnt == k) break;
		}

		while (cnt < k && !pq.empty()) {
			total += pq.top();
			pq.pop();
			cnt++;
		}

		return total;
    }
};

int main() {
	int n, k, w;
	cin >> n >> k >> w;

	vector<int> profits(n), capital(n);
	for (auto &x : profits) cin >> x;
	for (auto &x : capital) cin >> x;

	cout
		<< Solution().findMaximizedCapital(k, w, profits, capital)
		<< endl;
	return 0;
}
