#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(itr, start, end) for (int itr = start; itr < end; itr++)
#define v1(name, type) vector<type> name
#define v2(name, type, size, fill) vector<type> name(size, fill)
#define mat1(name, type) vector<vector<type>> name
#define mat2(name, type, row, col, fill) vector<vector<type>> name(row, vector<type>(col, fill))
#define printVec(size, vec)        \
    for (int i = 0; i < size; i++) \
        cout << vec[i] << " ";

#define printMat(row, col, mat)       \
    for (int i = 0; i < row; i++)     \
    {                                 \
        for (int j = 0; j < col; j++) \
            cout << mat[i][j] << " "; \
        cout << endl;                 \
    }

// START---->
#define n 4
mat2(sol, bool, n, n, false);

bool isSafe(int i, int j, int maze[n][n])
{
    if (i < n and j < n and maze[i][j])
        return true;
    return false;
}

bool solveMaze(int i, int j, int maze[n][n])
{
    if (i == n - 1 and j == n - 1)
    {
        sol[i][j] = 1;
        return true;
    }
    if (isSafe(i, j, maze))
    {
        sol[i][j] = 1;
        if (solveMaze(i + 1, j, maze))
            return true;
        else if (solveMaze(i, j + 1, maze))
            return true;
        sol[i][j] = 0;
    }
    return false;
}

int main()
{
    int maze[n][n] = {{1, 0, 0, 0},
                      {1, 1, 1, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 1}};

    if (solveMaze(0, 0, maze) == false)
        cout << "NO";
    else
    {
        cout << "YES" << endl;
        printMat(n, n, sol);
    }

    return 0;
}