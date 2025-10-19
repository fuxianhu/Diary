#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, ans;
int a[N];

int main() {
	freopen("ix.in", "r", stdin);
	freopen("ix.out", "w", stdout);
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)

		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int t = 1;

	for (int i = 2; i <= n; i++) {

		if (a[i] == a[i - 1])
			t++;
		else
			t = 1;
		ans = max(ans, t);
	}

	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}