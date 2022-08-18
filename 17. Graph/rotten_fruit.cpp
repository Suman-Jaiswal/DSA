// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int count = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    count++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int unit = 0;
        while (!q.empty())
        {
            if (count == 0)
                break;
            unit++;
            int sz = q.size();
            while (sz--)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int i = r + dx[k];
                    int j = c + dy[k];
                    if (i >= 0 and i < n and j >= 0 and j < m)
                    {
                        if (grid[i][j] == 1)
                        {
                            grid[i][j] = 2;
                            count--;
                            q.push({i, j});
                        }
                    }
                }
            }
        }
        if (count == 0)
            return unit;
        else
            return -1;
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
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends