#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void bubbleSort_ite(int arr[], int n)
{

    bool swapped;
    for (int i = 0; i < n; i++)
    {

        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void bubbleSort_rec(int arr[], int n)
{
    if (n == 1)
    {
        return;
    }

    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }
    if (swapped == false)
        return;
    bubbleSort_rec(arr, n - 1);
}

int main()
{
    int arr[] = {1, 10, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort_ite(arr, n);

    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}