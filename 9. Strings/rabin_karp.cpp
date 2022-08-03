#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(string str, string pat, int n, int m)
{
    int q = 101;
    int d = 5;
    int h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q; // d^(m-1) % q
    }

    int p = 0, t = 0;
    for (int i = 0; i < m; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + str[i]) % q;
    }
    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (str[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout << i << " ";
        }
        if (i < n - m)
        {
            t = (d * (t - str[i] * h) + str[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
}

int main()
{
    string str = "abcdecbcabccdbcac";
    string pat = "bc";

    solve(str, pat, str.length(), pat.length());

    return 0;
}