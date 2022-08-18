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

int solve(int f, int e)
{
    if (e == 1)
        return f;
    if (f == 1)
        return 1;
    if (f == 0)
        return 0;

    int res, min = INT_MAX;
    for (int i = 1; i <= f; i++)
    {
        res = max(solve(i - 1, e - 1), solve(f - i, e));
        if (res < min)
            min = res;
    }

    return min + 1;
}

int main()
{
    int f = 10;
    int e = 2;

    cout << solve(f, e);

    return 0;
}