#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void merge(int arr[], int a, int brr[0], int b)
{
    int i = 0, j = 0;
    while (i < a and j < b)
    {
        if (arr[i] <= brr[j])
        {
            cout << arr[i] << " ";
            i++;
        }
        else
        {
            cout << brr[j] << " ";
            j++;
        }
    }
    while (i < a)
    {
        cout << arr[i] << " ";
        i++;
    }
    while (j < b)
    {
        cout << brr[j] << " ";
        j++;
    }
}

int main()
{
    int arr[] = {10, 20, 50};
    int brr[] = {5, 50, 50};
    int a = sizeof(arr) / sizeof(arr[0]);
    int b = sizeof(brr) / sizeof(brr[0]);

    merge(arr, a, brr, b);

    return 0;
}