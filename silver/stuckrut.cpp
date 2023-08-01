#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector<array<int, 3>> Ncows, Ecows;
	for (int i = 0; i < N; i++) {
		char dir; int x, y;
		cin >> dir >> x >> y;
		if (dir == 'N') Ncows.push_back({x, y, i});
		else if (dir == 'E') Ecows.push_back({x, y, i});
		else return -1;
	}

	sort(begin(Ncows), end(Ncows));
	sort(begin(Ecows), end(Ecows), [](auto &left, auto &right) {
		return left[1] < right[1];
	});

	vector<int> stopped(N), kills(N);
	for (auto &Ecow : Ecows) {
		for (auto &Ncow : Ncows) {
			if (Ncow[0] > Ecow[0] && Ncow[1] < Ecow[1] && !stopped[Ncow[2]]) {
				if (Ecow[1] - Ncow[1] > Ncow[0] - Ecow[0]) {
					stopped[Ncow[2]] = 1;
					kills[Ecow[2]] += kills[Ncow[2]] + 1;
				} else if (Ecow[1] - Ncow[1] < Ncow[0] - Ecow[0]) {
					stopped[Ecow[2]] = 1;
					kills[Ncow[2]] += kills[Ecow[2]] + 1;
					break;
				}
			}
		}
	}

	for (auto &x : kills) {
		cout << x << '\n';
	}

	return 0;
}
