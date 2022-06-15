#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void partitioning(int arr[], int n)
{
    int l = 0, mid = 0, h = n - 1;
    while (mid <= h)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[l]);
            mid++;
            l++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[h]);
            h--;
        }
    }
}

int main()
{
    int arr[] = {1, 0, 1, 1, 1, 2, 2, 0, 2, 0, 1, 0, 2, 0, 1, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    partitioning(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}