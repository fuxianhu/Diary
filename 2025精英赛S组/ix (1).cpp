//2025.10.12  zyb  ix
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
multiset<int>s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("ix.in", "r", stdin);
	freopen("ix.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		auto it = s.upper_bound(a[i]);
		if (it != s.end())
			s.erase(it);
		s.insert(a[i]);
	}
	cout << s.size() << '\n';
	return 0;
}