#include <iostream>
using namespace std;

int firstOcc_Ite(int arr[], int n, int x)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (x > arr[mid])
            low = mid + 1;

        else if (x < arr[mid])
            high = mid - 1;

        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid;

            else
                high = mid - 1;
        }
    }

    return -1;
}

int firstOcc_Rec(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (x > arr[mid])
        return firstOcc_Rec(arr, mid + 1, high, x);

    else if (x < arr[mid])
        return firstOcc_Rec(arr, low, mid - 1, x);

    else
    {
        if (mid == 0 || arr[mid - 1] != arr[mid])
            return mid;

        else
            return firstOcc_Rec(arr, low, mid - 1, x);
    }
}

int main()
{

    int arr[] = {5, 10, 10, 10, 20}, n = 5;

    int x = 10;

    cout << firstOcc_Ite(arr, n, x);
    return 0;
}