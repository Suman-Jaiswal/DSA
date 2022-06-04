#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int count_subsets(int arr[], int n, int sum)
{
    if (n == 0)
        return sum == 0 ? 1 : 0;
    return count_subsets(arr, n - 1, sum) + count_subsets(arr, n - 1, sum - arr[n - 1]);
}

int main()
{
    int arr[3] = {10, 20, 15}, sum = 25, n = 3;
    cout << count_subsets(arr, 3, sum);
    return 0;
}