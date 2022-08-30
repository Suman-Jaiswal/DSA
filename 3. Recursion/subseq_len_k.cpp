#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(itr, start, end) for (int itr = start; itr < end; itr++)
#define v1(name, type) vector<type> name
#define v2(name, type, size) vector<type> name(size)
#define v3(name, type, size, fill) vector<type> name(size, fill)
#define mat1(name, type) vector<vector<type>> name
#define mat2(name, type, row, col) vector<vector<type>> name(row, vector<type>(col))
#define mat3(name, type, row, col, fill) vector<vector<type>> name(row, vector<type>(col, fill))

string solve(string s, int x, int k, int count, int n)
{
    if (k == n)
        return s;
    if (count = x)
    {
        int K = k;
        K -= count;
        int i = 0;
        string res;
        while (K > 0 and i < n)
        {
            res += s[i];
            if (s[i] == 'a')
                K--;
            i++;
        }

        while (res.length() < k)
        {
            res += "b";
        }

        return res;
    }

    else
    {
        if (s[n - 1] == 'b')
            return min(solve(s, x, k, count--, n - 1), solve(s, x--, k--, count--, n - 1));
        else
        {
            return min(solve(s, x, k--, count, n - 1), solve(s, x, k, count, n - 1));
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, k;
        cin >> x >> k;
        string s;
        cin >> s;
        int c = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'b')
                c++;
        }

        cout << solve(s, x, k, c, s.length());
    }

    return 0;
}