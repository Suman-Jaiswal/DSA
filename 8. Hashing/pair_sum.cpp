#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPair(int arr[], int n, int sum)
{
    unordered_set<int> set;
    for (int i = 0; i < n; i++)
    {
        if (set.find(sum - arr[i]) != set.end())
        {
            return true;
        }
        else
        {
            set.insert(arr[i]);
        }
    }
    return false;
}

int main()
{
    int arr[] = {8, 3, 4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;

    cout << isPair(arr, n, sum);

    return 0;
}