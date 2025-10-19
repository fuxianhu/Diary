#include <bits/stdc++.h>
using namespace std;
int a[100010];
int flag[100010];
int b[100010];

int main() {
	freopen("ix.in", "r", stdin);
	freopen("ix.out", "w", stdout);
	int n, x, t = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[x]++;
		if (flag[x] == 0) {
			flag[x] = 1;
			t++;
			b[t] = x;
		}
	}
	int mx = 0;
	for (int i = 1; i <= t; i++) {
		mx = max(mx, a[b[i]]);
	}
	cout << mx;
	return 0;
}