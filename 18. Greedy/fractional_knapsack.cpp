#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool myComp(pair<int, int> a, pair<int, int> b)
{
    int x1 = (double)a.first / a.second;
    int x2 = (double)b.first / b.second;
    return x1 > x2;
}

int fKnapS(int W, pair<int, int> arr[], int n)
{
    double res = 0.0;
    sort(arr, arr + n, myComp);
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i].second < W)
        {
            res += arr[i].first;
            W -= arr[i].second;
        }
        else
        {
            res = res + arr[i].first * ((double)W / arr[i].second);
            break;
        }
    }
    return res;
}

int main()
{
    pair<int, int> arr[] = {make_pair(120, 30), make_pair(100, 20), make_pair(60, 10)};

    int n = 3, W = 50;

    cout << fKnapS(W, arr, n);
    return 0;
}