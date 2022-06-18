#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int R = 4, C = 4;

void Print_transpose(int arr[R][C])
{
    for (size_t i = 0; i < C; i++)
    {
        for (size_t j = i + 1; j < R; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for (int i = 0; i < C; i++)
    {
        for (size_t j = 0; j < R; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[R][C] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };

    Print_transpose(arr);

    return 0;
}