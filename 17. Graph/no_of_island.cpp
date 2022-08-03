// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int isSafe(vector<vector<char>> &grid, int row, int col, vector<vector<bool>> &visited)
    {
        // row number is in range, column
        // number is in range and value is 1
        // and not yet visited
        return (row >= 0) && (row < grid.size()) &&
               (col >= 0) && (col < grid[0].size()) &&
               (grid[row][col] == '1' && !visited[row][col]);
    }
    // Function to find the number of islands.
    void dfsRec(vector<vector<char>> &grid, int row, int col, vector<vector<bool>> &visited)
    {
        static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        visited[row][col] = true;

        for (int k = 0; k < 8; ++k)
        {
            if (isSafe(grid, row + rowNbr[k], col + colNbr[k], visited))
                dfsRec(grid, row + rowNbr[k], col + colNbr[k], visited);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == false and grid[i][j] == '1')
                {
                    dfsRec(grid, i, j, visited);
                    res++;
                }
            }
        }

        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
} // } Driver Code Ends