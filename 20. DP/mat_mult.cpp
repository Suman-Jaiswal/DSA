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

int mchain(int arr[], int i, int j)
{
    if (i + 1 == j)
        return 0;

    int res = INT_MAX;

    for (int k = i + 1; k < j; k++)
    {
        res = min(res, mchain(arr, i, k) + mchain(arr, k, j) + arr[i] * arr[j] * arr[k]);
    }
    return res;
}

int main()
{
    int arr[] = {20, 10, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << mchain(arr, 0, n - 1);

    return 0;
}