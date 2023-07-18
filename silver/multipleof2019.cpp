#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string jar; cin >> jar;
	int N = jar.size(), mod = 2019;

	vector<int> rems(mod);
	rems[0] = 1;

	ll ans = 0;
	int pow = 1, num = 0;
	for (int i = N-1; i >= 0; i--) {
		num = (num + int(jar[i]-'0') * pow) % mod;
		ans += rems[num];
		rems[num]++;
		pow = (pow * 10) % mod;
	}

	cout << ans << endl;
	return 0;
}
