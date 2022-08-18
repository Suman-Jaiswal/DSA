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

int solve(string s1, string s2, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;

    if (s1[m - 1] == s2[n - 1])
    {
        return solve(s1, s2, m - 1, n - 1);
    }
    else
    {
        return 1 + min(min(solve(s1, s2, m - 1, n), solve(s1, s2, m, n - 1)), solve(s1, s2, m - 1, n - 1));
    }
}

int main()
{
    string s1 = "saturday";
    string s2 = "sunday";

    int m = s1.size();
    int n = s2.size();

    cout << solve(s1, s2, m, n);

    return 0;
}