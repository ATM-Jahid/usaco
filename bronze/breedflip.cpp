#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream cin("breedflip.in");
	ofstream cout("breedflip.out");

	int N; cin >> N;
	string A, B; cin >> A >> B;

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] != B[i]) {
			cnt++;
			int j;
			for (j = i+1; j < N && A[j] != B[j]; j++);
			i = j;
		}
	}
	cout << cnt << endl;

	return 0;
}
