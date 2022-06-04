#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isEq(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }

    int l_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (2 * l_sum == total - arr[i])
        {
            return true;
        }
        l_sum += arr[i];
    }
    return false;
}

int main()
{
    int n = 3, arr[n] = {-5, 15, 0};

    cout << isEq(arr, n);

    return 0;
}