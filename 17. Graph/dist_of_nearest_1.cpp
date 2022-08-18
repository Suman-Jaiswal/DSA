// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int isSafe(vector<vector<int>> &grid, int row, int col)
    {
        return (row >= 0) && (row < grid.size()) &&
               (col >= 0) && (col < grid[0].size()) &&
               (!grid[row][col]);
    }

    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));

        queue<pair<int, int>> q;

        static int rowNbr[] = {1, -1, 0, 0};
        static int colNbr[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dist[i][j] = 0;
                if (grid[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                }
            }
        }

        while (q.empty() == false)
        {
            pair<int, int> parent = q.front();
            q.pop();
            int row = parent.first;
            int col = parent.second;

            for (int k = 0; k < 4; k++)
            {
                if (isSafe(grid, row + rowNbr[k], col + colNbr[k]))
                {
                    grid[row + rowNbr[k]][col + colNbr[k]] = 1;
                    dist[row + rowNbr[k]][col + colNbr[k]] = dist[row][col] + 1;

                    q.push(make_pair(row + rowNbr[k], col + colNbr[k]));
                }
            }
        }
        return dist;
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
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
} // } Driver Code Ends