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

int solve(int n)
{
    if (n == 1 || n == 0)
        return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int left = i, right = n - i - 1;
        res += solve(left) * solve(right);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    cout << solve(n);

    return 0;
}