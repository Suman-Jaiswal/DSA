#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void get_coff(vector<vector<int>> mat, vector<vector<int>> &coff, int n, int index)
{
    for (int i = 1; i < n; i++)
    {
        int l = 0;
        for (int j = 0; j < n; j++)
        {
            if (index == j)
                continue;
            coff[i - 1][l] = mat[i][j];
            l++;
        }
    }
}

int determinantOfMatrix(vector<vector<int>> matrix, int n)
{
    if (n == 1)
        return matrix[0][0];
    if (n == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    vector<vector<int>> coff(n - 1, vector<int>(n - 1));
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        get_coff(matrix, coff, n, i);

        sum = sum + (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinantOfMatrix(coff, n - 1);
    }
    return sum;
}

int main()
{
    vector<vector<int>> M = {{1, 0, 2, -1},
                             {3, 0, 0, 5},
                             {2, 1, 4, -3},
                             {1, 0, 5, 0}};

    cout << determinantOfMatrix(M, 4);

    return 0;
}