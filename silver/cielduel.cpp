#include <bits/stdc++.h>
using namespace std;

int cntAttack(vector<int> &atk, vector<int> &fox) {
	int a = atk.size(), f = fox.size(), k = min(a, f);

	int ret = 0;
	for (int ik = 1; ik <= k; ik++) {
		int temp = 0;
		for (int ij = 0; ij < ik; ij++) {
			if (fox[f-ik+ij] >= atk[ij]) {
				temp += fox[f-ik+ij] - atk[ij];
			} else break;
		}
		ret = max(ret, temp);
	}

	return ret;
}

int cntFreebies(vector<int> &atk, vector<int> &def, vector<int> &fox) {
	int a = atk.size(), d = def.size(), f = fox.size();
	if (a + d >= f) return 0;

	int covAtk = 0, covDef = 0;
	int pa = 0, pd = 0, pf = 0;

	vector<int> used(f);
	while (pd < d && pf < f) {
		if (def[pd] < fox[pf]) {
			used[pf] = 1;
			pd++;
			pf++;
		} else {
			pf++;
		}
	}
	if (pd == d) covDef = 1;

	pf = 0;
	while (pa < a && pf < f) {
		if (!used[pf] && atk[pa] <= fox[pf]) {
			pa++;
			pf++;
		} else {
			pf++;
		}
	}
	if (pa == a) covAtk = 1;

	if (covAtk && covDef) {
		int ret = 0;
		for (int i = 0; i < f; i++) {
			if (!used[i]) ret += fox[i];
		}
		for (int i = 0; i < a; i++) {
			ret -= atk[i];
		}
		return ret;
	} else return 0;
}

int main() {
	int n, m; cin >> n >> m;
	vector<int> attack, defense;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int v; cin >> v;
		if (s == "ATK") attack.push_back(v);
		else defense.push_back(v);
	}
	vector<int> cards(m);
	for (auto &x : cards) cin >> x;

	sort(begin(attack), end(attack));
	sort(begin(defense), end(defense));
	sort(begin(cards), end(cards));

	int ans = cntFreebies(attack, defense, cards);
	ans = max(ans, cntAttack(attack, cards));
	cout << ans << endl;
	return 0;
}
