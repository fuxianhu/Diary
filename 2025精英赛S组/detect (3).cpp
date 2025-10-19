#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int n;
	cin >> n;
	int a = n, q = 2;

	if (n < 3) {
		cout << "1 1" << endl;

		for (int i = 1; i <= n - 1; i++) {

			cout << i << " " << i + 1 << endl;
		}

		return 0;
	}

	n--;
	n *= 8;
	n++;
	n = sqrt(n);
	n -= 2;
	n = (double)n / 2 + 0.99;
	cout << n + 1 << " 1" << endl;

	for (int i = 1; i <= a; i++) {

		for (int j = 1; j <= i; j++) {

			if (j == 1) {
				cout << "1 " << q << endl;
				q++;
			} else {
				cout << q - 1 << " " << q << endl;
				q++;
			}

			if (q > a) {
				return 0;
			}
		}
	}

	return 0;
}