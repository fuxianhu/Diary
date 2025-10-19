#include <bits/stdc++.h>

using namespace std;
using num = long long;

const num nn = 2e6 + 10;
num a[nn], v[nn];
bool yes[nn];
num n, k, r, x, c, curr = 0, curc = 0;
__int128_t ans = 0;

void print(__int128_t xx) {
	if (xx < 0) {
		cout << '-';
		print(-xx);
		return;
	}
	if (xx < 10) {
		cout << (num)xx;
		return;
	}
	print(xx / 10);
	cout << num(xx % 10);
}

struct attack {
	num i;
	num get() const {
		num res = 0;
		if (yes[i] > 0) {
			res += (n - i) * r;
		}
		res += (n - i) * c;
		return res;
	}
	bool operator>(const attack &rhs) const {
		return get() > rhs.get();
	}
};

//auto &dbg = cerr;

int main() {
	freopen("cross.in", "r", stdin);
	freopen("cross.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k >> r >> x >> c;
	num sum = 0;
	for (num i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
		if (sum > 0) {
			yes[i] = 1;
			--sum;
		}
		v[i] = attack{i}.get();
//		cerr << v[i] << ' ';
	}
	for (num i = 0; i < n; ++i) {
		curr += a[i];
		ans += -curr * r + x + curc * c;
	}
//	cerr << "a";
//	print(ans);
	sort(v, v + n, greater<num>());
	for (num i = 0; i < min(n, k); ++i) {
		ans += v[i];
	}
	print(ans);
}