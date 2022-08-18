// longest common subsequence

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(itr, start, end) for (int itr = start; itr < end; itr++)
#define v1(name, type) vector<type> name
#define v2(name, type, size, fill) vector<type> name(size, fill)
#define mat1(name, type) vector<vector<type>> name
#define mat2(name, type, row, col, fill) vector<vector<type>> name(row, vector<type>(col, fill))

int solve(string s1, string s2, int n, int m)
{
    if (n == -1 || m == -1)
        return 0;
    if (s1[n] == s2[m])
    {
        return 1 + solve(s1, s2, n - 1, m - 1);
    }
    else
    {
        return max(solve(s1, s2, n - 1, m), solve(s1, s2, n, m - 1));
    }
}

int main()
{
    string s1 = "AXYZ";
    string s2 = "BAZ";

    int n = s1.length();
    int m = s2.length();

    cout << solve(s1, s2, n - 1, m - 1);

    return 0;
}