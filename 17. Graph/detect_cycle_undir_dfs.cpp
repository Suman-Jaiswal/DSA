#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// DFS based soln

bool isCyclicConnected(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for (int u : adj[s])
    {
        if (!visited[u])
        {
            if (isCyclicConnected(adj, u, visited, s))
                return true;
        }
        else if (u != parent)
            return true;
    }
    return false;
}

bool solve(vector<int> adj[], int v)
{
    bool visited[v] = {false};
    for (int i = 0; i < v; i++)
        if (!visited[i])
            if (isCyclicConnected(adj, i, visited, -1))
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