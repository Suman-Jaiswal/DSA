#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int arr[7] = {2, 3, 10, 6, 4, 8, 1};

    int res = arr[1] - arr[0], minVal = arr[0];

    // for max diff value with order----->

    for (int i = 1; i < 7; i++)
    {
        res = max(res, arr[i] - minVal);
        minVal = min(minVal, arr[i]);
    }
    cout << res;

    // max diff value without order------>

    int maxVal = 0;

    for (int i = 0; i < 7; i++)
    {
        maxVal = max(maxVal, arr[i]);
        minVal = min(minVal, arr[i]);
    }

    cout << maxVal - minVal;

    return 0;
}