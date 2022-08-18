// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int, pair<int, int>> p;

class Solution
{
public:
    bool safe(int r, int c, vector<vector<bool>> &vis, int n)
    {
        return (r >= 0 and c >= 0 and r < n and c < n and !vis[r][c]);
    }
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        dis[0][0] = grid[0][0];

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        priority_queue<p, vector<p>, greater<p>> pq;

        pq.push({grid[0][0], {0, 0}});

        while (pq.size())
        {
            p pair = pq.top();
            pq.pop();
            int distyet = pair.first;
            int r = pair.second.first;
            int c = pair.second.second;

            for (int k = 0; k < 4; k++)
            {
                int i = r + dx[k];
                int j = c + dy[k];
                if (safe(i, j, vis, n))
                {
                    vis[i][j] = true;
                    if (distyet + grid[i][j] < dis[i][j])
                    {
                        dis[i][j] = distyet + grid[i][j];
                        pq.push({dis[i][j], {i, j}});
                    }
                }
            }
        }
        return dis[n - 1][n - 1];
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.minimumCostPath(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends