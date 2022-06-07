#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key and j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {20, 5, 40, 60, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}