#include <bits/stdc++.h>
using namespace std;
#define ll long long int;

int jumpSearch(int arr[], int n, int x)
{
    int jump = sqrt(n);
    int i = 0;
    while (i <= n && arr[i] < x)
        i += jump;
    i -= jump;
    for (int j = i; j < i + jump; j++)
    {
        if (arr[j] == x)
            return j;
    }
    return -1;
}

int main()
{
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21,
                 34, 55, 89, 144, 233, 377, 610};
    int x = 1;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = jumpSearch(arr, n, x);
    (result == -1) ? cout << "not found" : cout << result;
    return 0;
}