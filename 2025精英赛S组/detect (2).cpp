#include <bits/stdc++.h>
#define INF 0x7fffffff
typedef long long ll;
using namespace std;
int n, poi = 2;

void dfs(int u) {
	if (poi <= n) {
		printf("%d %d\n", u, poi++);
	} else
		return;
	if (poi <= n) {
		printf("%d %d\n", u, poi++);
	} else
		return;
	dfs(poi - 1);
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &n);
	if (n == 1) {
		printf("1 1");
		return 0;
	}
	printf("%d %d\n", n - 1, 1);
	dfs(1);
	return 0;
}