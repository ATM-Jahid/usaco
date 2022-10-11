#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("guess.in", "r", stdin);
	freopen("guess.out", "w", stdout);

	int n; cin >> n;
	vector<vector<string>> props(n);
	for (auto &el : props) {
		string name; cin >> name;
		int k; cin >> k;
		for (int i = 0; i < k; i++) {
			string tmp; cin >> tmp;
			el.push_back(tmp);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			set<string> joint;
			for (auto el : props[i]) joint.insert(el);
			for (auto el : props[j]) joint.insert(el);
			int com = props[i].size() + props[j].size() - joint.size() + 1;
			ans = max(ans, com);
		}
	}

	cout << ans << '\n';
	return 0;
}
