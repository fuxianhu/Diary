#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;

struct edge {
	int u, v;
};

int size[N], dep[N];
vector<int> adj[N];

void dfs(int u, int parent) {
	size[u] = 1;
	dep[u] = dep[parent] + 1;

	for (auto &v : adj[u]) {
		if (v == parent)
			continue;
		dfs(v, u);

		size[u] += size[v];
	}
}

void solve(int n) {
	vector<edge> ans;
	ans.reserve(n);

	for (int i = 2; i <= n; i++) {
		int u, v = i;
		if (i % 2 == 0) {
			u = i - 1;
		} else if (i % 2 == 1) {
			u = i - 2;
		}

		ans.push_back({u, v});
		adj[u].push_back(v);
	}

	cout << n - 1 << " " << 1 << "\n";
	for (edge &ed : ans) {
		cout << ed.u << " " << ed.v << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);

	int n;
	cin >> n;

	if (n == 1) {
		cout << 1 << " " << 1;
	} else if (n == 2) {
		cout << 1 << " " << 1 << "\n";
		cout << 1 << " " << 2;
	} else if (n == 3) {
		cout << 2 << " " << 1 << "\n";
		cout << 1 << " " << 2 << "\n";
		cout << 1 << " " << 3;
	} else if (n == 4) {
		cout << 3 << " " << 1 << "\n";
		cout << 1 << " " << 2 << "\n";
		cout << "1 3\n";
		cout << "3 4\n";
	} else if (n == 5) {
		cout << "4 1\n";
		cout << "1 2\n";
		cout << "1 3\n";
		cout << "3 5\n";
		cout << "3 4\n";
	} else if (n == 6) {
		cout << "5 1\n";
		cout << "1 2\n";
		cout << "1 3\n";
		cout << "3 5\n";
		cout << "3 4\n";
		cout << "5 6\n";
	} else {
		solve(n);
	}

//	solve(n);

	return 0;
}