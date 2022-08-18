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

int solve(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    loop(i, 1, n)
    {
        int m = 0;
        loop(j, 0, i)
        {
            if (arr[j] < arr[i])
                m = max(m, lis[j]);
        }
        lis[i] = m + 1;
    }
    int res = 0;
    loop(i, 0, n) res = max(res, lis[i]);
    return res;
}

int main()
{
    int arr[] = {3, 4, 2, 8, 10, 5, 1};
    int n = 7;

    cout << solve(arr, n);

    return 0;
}