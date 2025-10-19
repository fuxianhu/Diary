#include <bits/stdc++.h>
constexpr int MAXN = 1e5 + 5;


int n, x, d[MAXN], maxd = 0;

int main()
{
    freopen("fix.in", "r", stdin);
    freopen("fix.out", "w", stdout);
    
    std::cin >> n >> x;
    for (int i =  1; i <= n; i++)
    {
        std::cin >> d[i];
        maxd = std::max(maxd, d[i]);
    }
    std::cout << ceil(maxd / x) << std::endl;




    return 0;
}