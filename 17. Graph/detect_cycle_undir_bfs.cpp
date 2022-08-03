#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isCyclicConnected(vector<int> adj[], int s, int v, bool visited[])
{
    vector<int> parent(v, -1);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (int x : adj[u])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
                parent[x] = u;
            }
            else if (parent[u] != x)
            {
                return true;
            }
        }
    }
    return false;
}

bool solve(vector<int> adj[], int v)
{
    bool visited[v] = {false};
    for (int i = 0; i < v; i++)
        if (!visited[i] && isCyclicConnected(adj, i, v, visited))
            return true;
    return false;
}

int main()
{
    int v = 5;
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);

    cout << solve(adj, v);

    return 0;
}