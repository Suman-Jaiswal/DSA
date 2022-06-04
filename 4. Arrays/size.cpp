#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void fn(vector<int> &a)
{
    a[0] = 1;
    a[1] = 1;
}

int main()
{
    vector<int> arr(2, 0);

    cout << arr[0] << " " << arr[1];

    fn(arr);

    cout << arr[0] << " " << arr[1];

    return 0;
}