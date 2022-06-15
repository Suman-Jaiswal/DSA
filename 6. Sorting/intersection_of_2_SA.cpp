#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printIntersection(int arr[], int brr[], int a, int b)
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
            i++;
        }
        else if (arr[i] > brr[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    int arr[] = {2, 20, 20, 40, 60};
    int a = sizeof(arr) / sizeof(arr[0]);
    int brr[] = {10, 20, 20, 20};
    int b = sizeof(brr) / sizeof(brr[0]);

    printIntersection(arr, brr, a, b);

    return 0;
}