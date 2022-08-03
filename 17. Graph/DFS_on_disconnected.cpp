#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            DFSRec(adj, u, visited);
        }
    }
}

int DFS(vector<int> adj[], int v)
{

    bool visited[v] = {false};
    int c = 0;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            DFSRec(adj, i, visited);
            c++;
        }
    }
    cout << endl
         << "no of islands: ";
    return c;
}

int main()
{
    int v = 5;
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);

    cout << DFS(adj, v);

    return 0;
}