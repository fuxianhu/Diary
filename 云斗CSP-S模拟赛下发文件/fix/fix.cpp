#include <bits/stdc++.h>

int n;
std::string s;
std::stack<char> st;

int main()
{
    freopen("fix.in", "r", stdin);
    freopen("fix.out", "w", stdout);
    std::cin >> n;
    if (n == 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }
    std::cin >> s;
    for (int i = 0; i < s.length(); i ++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else if (st.top() == '(' && s[i] == ')')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    // std::cout << ceil(st.size() / 2) << std::endl;

    int ans = 0;

    while (!st.empty())
    {
        if (st.top() == '(')
        {
            ans ++;
            st.pop();
            if (!st.empty())
            {
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    ans ++;
                    st.pop();
                }
            }
            // st.push(')');
        }
        else
        {
            char temp = st.top();
            st.pop();
            if (!st.empty())
            {
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    ans ++;
                    st.pop();
                }
            }
            else
            {
                st.push(temp);
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}