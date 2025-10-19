#include <bits/stdc++.h>
using namespace std;
long long a[10005], n, maxx = -1;

int main() {
	freopen("ix.in", "r", stdin);
	freopen("ix.out", "w", stdout);
	cin >> n;
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[x]++;
		if (a[x] > maxx) {
			maxx = a[x];
		}
	}
	cout << maxx;
	return 0;
}