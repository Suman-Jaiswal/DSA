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

bool ispalind(string s, int l, int r)
{
    while (l <= r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int solve(string s, int i, int j)
{
    if (ispalind(s, i, j))
        return 0;
    int res = INT_MAX;

    for (int k = i; k < j; k++)
    {
        res = min(res, 1 + solve(s, i, k) + solve(s, k + 1, j));
    }
    return res;
}

int main()
{
    string s = "geek";

    cout << solve(s, 0, s.length() - 1);

    return 0;
}