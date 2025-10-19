#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define ll __int128

using namespace std;

const int N = 2e6 + 10;

ll n, k, r, x, c, ans, lst;
ll s1[N], s2[N], s3[N];

ll read (void) {
    ll tmp = 0;
    char ch;
    while (isspace(ch = getchar()));
    while (isdigit(ch))
        tmp = tmp * 10 + ch - '0', ch = getchar();
    return tmp;
}

void write (ll x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}

int main (void) {
    freopen ("cross.in", "r", stdin);
    freopen ("cross.out", "w", stdout);
    n = read(), k = read(), r = read(), x = read(), c = read(), lst = k;
    rep(i, 1, k)
        s2[i]++;
    rep(i, 1, n) {
        s1[i] = read(), s1[i] += s1[i - 1];
        if (s1[i]) {
            if (i > k) {
                while (lst > 0 && (s3[lst] || !s2[lst]))
                    lst--;
                if (lst > 0 && (n - i + 1) * (r + c) > (n - lst + 1) * c) {
                    s2[lst]--, s2[i]++, s1[i]--, s3[i]++;
                    if (s3[lst])
                        s3[lst]--, s1[lst]++;
                }
            }
            else
                s1[i]--, s3[i]++;
        }
    }
    rep(i, 1, n) {
        s2[i] += s2[i - 1];
        // write(s1[i]), putchar(' '), write(s2[i]), puts("");
        ans += -r * s1[i] + x + c * s2[i];
    }
    write(ans);
    return 0;
}
