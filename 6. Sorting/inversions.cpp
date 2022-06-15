#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int count_and_merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (size_t i = 0; i < n1; i++)
    {
        left[i] = arr[i + l];
    }
    for (size_t i = 0; i < n2; i++)
    {
        right[i] = arr[i + m + 1];
    }

    int res = 0, i = 0, j = 0, k = l;
    while (i < n1 and j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            res += (n1 - i);
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }

    return res;
}

int count_inversions(int arr[], int l, int r)
{
    int res = 0;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        res += count_inversions(arr, l, m);
        res += count_inversions(arr, m + 1, r);
        res += count_and_merge(arr, l, m, r);
    }
    return res;
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << count_inversions(arr, 0, n - 1);

    return 0;
}