#include <bits/stdc++.h>


int t, n;

int main()
{
    freopen("num.in", "r", stdin);
    freopen("num.out", "w", stdout);

    
    std::cin >> t;
    for (int i = 1; i <= t; i++)
    {
        std::cin >> n;
        if (n % 2 == 1)
        {
            std::cout << "YES" << std::endl;
            continue;
        }
        int xx = ceil(sqrt(n));
        if (pow(xx, 2) == n)
        {
            std::cout << "YES" << std::endl;
            continue;
        }
        else
        {
            bool flag = false;
            for (int x = xx; x <= n; x++)
            {
                for (int y = 1; y < x; y++)
                {
                    if (n == pow(x, 2) - pow(y, 2))
                    {
                        flag = true;
                        std::cout << "YES" << std::endl;
                        break;
                    }
                }
                if (flag)
                {
                    break;
                }
            }
            if (!flag)
            {
                std::cout << "NO" << std::endl;
            }
        }
    }


    return 0;
}