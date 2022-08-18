#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(itr, start, end) for (int itr = start; itr < end; itr++)
#define v1(name, type) vector<type> name
#define v2(name, type, size, fill) vector<type> name(size, fill)
#define mat1(name, type) vector<vector<type>> name
#define mat2(name, type, row, col, fill) vector<vector<type>> name(row, vector<type>(col, fill))

int fibonacci(int n, vector<int> &memo)
{
    if (memo[n] == -1)
    {
        if (n == 1 || n == 0)
        {
            memo[n] = n;
        }
        else
            memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    }
    return memo[n];
}

int main()
{
    int t;
    cin >> t;
    v2(memo, int, t + 1, -1);

    cout << fibonacci(t, memo);

    return 0;
}