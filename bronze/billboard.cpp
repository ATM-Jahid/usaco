#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	int a[4], b[4], c[4];
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;
	for (int &x : c) cin >> x;

	int acx = max(min(a[2],c[2]) - max(a[0],c[0]), 0);
	int acy = max(min(a[3],c[3]) - max(a[1],c[1]), 0);
	int bcx = max(min(b[2],c[2]) - max(b[0],c[0]), 0);
	int bcy = max(min(b[3],c[3]) - max(b[1],c[1]), 0);

	cout << (a[2]-a[0])*(a[3]-a[1]) - acx*acy
		+ (b[2]-b[0])*(b[3]-b[1]) - bcx*bcy << '\n';
	return 0;
}
