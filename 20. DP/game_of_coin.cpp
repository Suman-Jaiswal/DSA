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

int sol(int arr[], int i, int j)
{
    if (i + 1 == j)
        return max(arr[i], arr[j]);
    return max(
        arr[i] + min(sol(arr, i + 2, j), sol(arr, i + 1, j - 1)),
        arr[j] + min(sol(arr, i + 1, j - 1), sol(arr, i, j - 2)));
}

int main()
{

    int n = 4;

    int arr[] = {20, 5, 4, 6};

    cout << sol(arr, 0, n - 1);

    return 0;
}