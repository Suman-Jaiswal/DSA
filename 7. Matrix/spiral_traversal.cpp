#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

const int R = 1, C = 1;

void printSpiral(int mat[R][C], int R, int C)
{
    int top = 0, left = 0, bottom = R - 1, right = C - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            cout << mat[top][i] << " ";

        top++;

        for (int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";

        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                cout << mat[bottom][i] << " ";

            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                cout << mat[i][left] << " ";

            left++;
        }
    }
}

int main()
{
    int arr[R][C] = {{1}};

    printSpiral(arr, R, C);

    return 0;
}