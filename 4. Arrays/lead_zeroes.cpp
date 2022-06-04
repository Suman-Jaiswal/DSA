#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int arr[6] = {10, 8, 0, 0, 12, 0}, n = 6;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count++;
        else
        {
            swap(arr[i], arr[i - count]);
        }
    }

    int i = 0;
    while (i < n)
    {
        cout << arr[i] << " ";
        i++;
    }

    return 0;
}