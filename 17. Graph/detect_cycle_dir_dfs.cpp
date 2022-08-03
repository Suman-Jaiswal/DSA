#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool DFSRec(vector<int> adj[], int s, bool visited[], bool RecStack[])
{
    visited[s] = true;
    RecStack[s] = true;

    for (int u : adj[s])
    {
        if (visited[u] == false and DFSRec(adj, u, visited, RecStack))
            return true;
        else if (RecStack[u])
            return true;
    }

    RecStack[s] = false;
    return false;
}

bool DFS(vector<int> adj[], int v)
{
    bool visited[v] = {false};
    bool RecStack[v] = {false};
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (DFSRec(adj, i, visited, RecStack))
                return true;
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    if (DFS(adj, V))
        cout << "Cycle found";
    else
        cout << "No cycle found";

    return 0;
}
