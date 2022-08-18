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

int searchCiel(vector<int> &tail, int x)
{
    int l = 0, h = tail.size() - 1;
    while (l < h)
    {
        int mid = (l + h) / 2;
        if (tail[mid] >= x)
            h = mid;
        else
            l = mid + 1;
    }
    return h;
}

int solve(int arr[], int n)
{
    v1(tail, int);
    tail.push_back(arr[0]);
    int len = 1;
    for (size_t i = 1; i < n; i++)
    {
        if (arr[i] > tail[len - 1])
        {
            tail.push_back(arr[i]);
            len++;
        }
        else
        {
            int ind = searchCiel(tail, arr[i]);
            tail[ind] = arr[i];
        }
    }
    return len;
}

int main()
{
    int arr[] = {3, 4, 2, 8, 10, 5, 1};
    int n = 7;

    cout << solve(arr, n);

    return 0;
}