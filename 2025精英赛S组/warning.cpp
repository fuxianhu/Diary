#include <bits/stdc++.h>
#define INF 0x7fffffff
typedef long long ll;
using namespace std;
const int N = 5080;
const int MOD = 998244353;
bool st;

inline ll qpow(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y & 1)
			res = 1LL * res * x % MOD;
		x = 1LL * x * x % MOD;
		y >>= 1;
	}
	return res;
}
int c, t, n, k, val[N], tot = 0, head[N];

struct edge {
	int nxt, to;
} e[N << 2];

void addEdge(int u, int v) {
	e[++tot] = (edge) {
		head[u], v
	};
	head[u] = tot;
	e[++tot] = (edge) {
		head[v], u
	};
	head[v] = tot;
}
int ans, cntans;
int f[N][N], cnt[N][N], siz[N];

inline void add(int &x, int y) {
	x = x + y > MOD ? x + y - MOD : x + y;
}

void dfs1(int u, int anc) {
	siz[u] = 1;
	f[u][1] = val[u];
	cnt[u][1] = 1;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == anc)
			continue;
		dfs1(v, u);
		for (int j = siz[u]; j >= 1; j--) {
			for (int i = 1; i <= min(siz[v], k); i++) {
				add(f[u][j + i], 1LL * (1LL * f[u][j]*cnt[v][i] % MOD + 1LL * f[v][i]*cnt[u][j] % MOD) % MOD);
				add(cnt[u][j + i], 1LL * cnt[u][j]*cnt[v][i] % MOD);
			}
		}
		siz[u] += siz[v];
	}
}

int lstf[N][N], lstcnt[N][N];
void dfs2(int u, int anc) {
	if (anc) {
		for (int i = 0; i <= n + 1; i++)
			f[u][i] = cnt[u][i] = 0;
		f[u][1] = val[u];
		cnt[u][1] = 1;
		int nowsiz = 1;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (v == anc)
				continue;
			for (int j = nowsiz; j >= 1; j--) {
				for (int i = 1; i <= min(siz[v], k); i++) {
					add(f[u][j + i], 1LL * (1LL * f[u][j]*cnt[v][i] % MOD + 1LL * f[v][i]*cnt[u][j] % MOD) % MOD);
					add(cnt[u][j + i], 1LL * cnt[u][j]*cnt[v][i] % MOD);
				}
			}
			nowsiz += siz[v];
		}
		for (int j = nowsiz; j >= 1; j--) {
			for (int i = 1; i <= min(n - siz[u], k); i++) {
				add(f[u][j + i], 1LL * (1LL * f[u][j]*cnt[anc][i] % MOD + 1LL * f[anc][i]*cnt[u][j] % MOD) % MOD);
				add(cnt[u][j + i], 1LL * cnt[u][j]*cnt[anc][i] % MOD);
			}
		}
		for (int i = 1; i <= n; i++) {
			add(ans, f[u][i]), add(cntans, cnt[u][i]), add(ans, 1LL * cnt[u][i]*val[u] % MOD);
			//cout << u << " " << i << ":" << cnt[u][i] << endl;
		}
	}
	for (int i = 0; i <= n; i++)
		lstf[u][i] = f[u][i], lstcnt[u][i] = cnt[u][i];
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == anc)
			continue;
		for (int j = 0; j <= n; j++)
			f[u][j] = lstf[u][j], cnt[u][j] = lstcnt[u][j];
		for (int j = 1; j <= n - siz[v]; j++) {
			for (int i = 1; i <= min(siz[v], k); i++) {
				add(cnt[u][j + i], -1LL * cnt[u][j]*cnt[v][i] % MOD + MOD);
				add(f[u][j + i], -1LL * (1LL * f[u][j]*cnt[v][i] % MOD + 1LL * f[v][i]*cnt[u][j] % MOD) % MOD + MOD);
			}
		}
		dfs2(v, u);
	}
	siz[u] = 1;
	f[u][1] = val[u];
	cnt[u][1] = 1;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == anc)
			continue;
		dfs1(v, u);
		for (int j = siz[u]; j >= 1; j--) {
			for (int i = 1; i <= min(siz[v], k); i++) {
				add(f[u][j + i], 1LL * (1LL * f[u][j]*cnt[v][i] % MOD + 1LL * f[v][i]*cnt[u][j] % MOD) % MOD);
				add(cnt[u][j + i], 1LL * cnt[u][j]*cnt[v][i] % MOD);
			}
		}
		siz[u] += siz[v];
	}
}
bool en;

signed main() {
	freopen("warning.in", "r", stdin);
	freopen("warning.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			head[i] = 0;
		tot = ans = cntans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &val[i]);
		for (int i = 1, x, y; i < n; i++) {
			scanf("%d%d", &x, &y);
			addEdge(x, y);
		}
		//cout << "!";
		int result = 0;
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= n + 1; j++)
				f[i][j] = cnt[i][j] = 0;
		}
		dfs1(1, 0);
		for (int i = 1; i <= n; i++) {
			add(ans, f[1][i]), add(cntans, cnt[1][i]), add(ans, 1LL * cnt[1][i]*val[1] % MOD);
			//cout << u << " " << i << ":" << cnt[u][i] << endl;
		}
		dfs2(1, 0);
		printf("%d\n", 1LL * ans * qpow(cntans, MOD - 2) % MOD);
	}
	return 0;
}