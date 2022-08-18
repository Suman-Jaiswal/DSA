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

#define n 4

mat2(board, bool, n, n, false);

bool isSafe(int row, int col)
{
    loop(i, 0, col)
    {
        if (board[row][i])
            return false;
    }

    for (int i = row, j = col; i >= 0 and j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    for (int i = row, j = col; i < n and j >= 0; i++, j--)
    {
        if (board[i][j])
            return false;
    }
    return true;
}

bool solve(int col)
{
    if (col == n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = true;
            printMat(n, n, board);
            cout << endl;
            if (solve(col + 1))
                return true;
            board[i][col] = false;
        }
    }
    return false;
}

int main()
{
    if (solve(0) == false)
        cout << "Not Possible!";
    else
    {
        printMat(n, n, board);
    }

    return 0;
}