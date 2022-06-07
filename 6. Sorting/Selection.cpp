#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_id = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_id])
                min_id = j;
        }
        swap(arr[i], arr[min_id]);
    }
}

int main()
{
    int arr[] = {10, 5, 8, 20, 2, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}