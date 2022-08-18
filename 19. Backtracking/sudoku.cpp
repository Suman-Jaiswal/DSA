#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(itr, start, end) for (int itr = start; itr < end; itr++)
#define v1(name, type) vector<type> name
#define v2(name, type, size, fill) vector<type> name(size, fill)
#define mat1(name, type) vector<vector<type>> name
#define mat2(name, type, row, col, fill) vector<vector<type>> name(row, vector<type>(col, fill))
#define printMat(row, col, mat)       \
    for (int i = 0; i < row; i++)     \
    {                                 \
        for (int j = 0; j < col; j++) \
            cout << mat[i][j] << " "; \
        cout << endl;                 \
    }
#define N 9

mat2(grid, int, N, N, 0);

bool isSafe(int row, int col, int num)
{
    loop(i, 0, N)
    {
        if (grid[i][col] == num || grid[row][i] == num)
            return false;
    }

    int sq = 3;
    int rs = row - row % sq;
    int cs = col - col % sq;

    loop(i, rs, sq + rs)
        loop(j, cs, sq + cs) if (grid[i][j] == num) return false;

    return true;
}

bool solve(vector<vector<int>> &grid)
{
    int i, j;
    bool isEmpty = true;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty)
        {
            break;
        }
    }

    if (isEmpty)
    {
        return true;
    }

    loop(n, 1, N + 1)
    {
        if (isSafe(i, j, n))
        {
            grid[i][j] = n;
            if (solve(grid))
                return true;
            grid[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    loop(i, 0, N)
    {
        loop(j, 0, N)
        {
            cin >> grid[i][j];
        }
    }

    if (solve(grid) == true)
    {
        printMat(N, N, grid);
    }
    else
        cout << "No solution exists!";

    return 0;
}