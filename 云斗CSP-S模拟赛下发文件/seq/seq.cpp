#include <bits/stdc++.h>

constexpr int MAXN = 5e5 + 10;

int n = 0, a[MAXN];

void fastRead()
{
    for (int i = 0; ; i++)
    {
        int x = getchar();
        if (x == 10 || x == 32)
        {
            break;
        }
        n += (x - '0') * pow(10, i);
    }
    for (int i = 1; i <= n; i++)
    {
        int j = 0;
        a[i] = 0;
        while (true)
        {
            int x = getchar();
            if (x == 32 || x == 10)
            {
                break;
            }
            a[i] += (x - '0') * pow(10, j);
            j++;
        }
    }
}

void testRead()
{
    std::cout << n << '\n';
    for (int i = 1; i <= n; i++)
    {
        std::cout << a[i] << ' ';
    }
}

int main()
{
    freopen("seq.in", "r", stdin);
    freopen("seq.out", "w", stdout);
    // testRead()

    fastRead();
    int tnt = 0;
    if (a[1] != a[n])
    {
        tnt++;
    }
    else
    {
        for (int i = 2; i <= floor(n / 2); i++)
        {
            if (!(a[i - 1] < a[i] && a[i] == a[n - i + 1]))
            {
                tnt++;
            }
        }
    }
    if (tnt == 0)
    {
        putchar('0');
        putchar('\n');
    }
    else
    {
        // printf("%d\n", tnt);
        printf("2\n");
    }


    return 0;
}