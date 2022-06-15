#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printUnion(int arr[], int brr[], int a, int b)
{
    int i = 0, j = 0;
    while (i < a and j < b)
    {
        if (arr[i] == arr[i - 1] and i > 0)
        {
            i++;
            continue;
        }
        if (brr[j] == brr[j - 1] and j > 0)
        {
            j++;
            continue;
        }

        if (arr[i] < brr[j])
        {
            cout << arr[i] << " ";
            i++;
        }
        else if (arr[i] > brr[j])
        {
            cout << brr[j] << " ";
            j++;
        }
        else
        {
            cout << arr[i] << " ";
            i++;
            j++;
        }
    }
    while (i < a)
    {
        if (arr[i] != arr[i - 1] and i > 0)
        {
            cout << arr[i] << " ";
            i++;
        }
    }
    while (j < b)
    {
        if (brr[j] != brr[j - 1] and j > 0)
        {
            cout << brr[j] << " ";
            j++;
        }
    }
}

int main()
{
    int arr[] = {2, 10, 20, 20};
    int a = sizeof(arr) / sizeof(arr[0]);
    int brr[] = {3, 20, 40};
    int b = sizeof(brr) / sizeof(brr[0]);

    printUnion(arr, brr, a, b);

    return 0;
}