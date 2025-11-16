#include <iostream>
#include <stack>
#include <queue>
#include <cmath>

constexpr int MAXN = 5e5 + 10;

int a[MAXN]; // , b[MAXN];
int p1 = 1, p2 = 1;

int n;
std::stack<int> st;
std::queue<int> qe;
int x;

int main()
{
    std::cin >> n;
    for (auto i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (auto i = 1; i <= n; i++)
    {
        std::cin >> x;
        qe.push(x);
    }
    auto idx = 1;
    while (!qe.empty())
    {
        bool flag = true;
        while (true)
        {
            st.push(a[idx]);
            idx++;
            if (!st.empty())
            {
                if (st.top() == qe.front())
                {
                    st.pop();
                    qe.pop();
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;


    return 0;
}