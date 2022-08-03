#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], int s, stack<int> &st, bool visited[])
{
    visited[s] = true;
    for (int v : adj[s])
    {
        if (visited[v] == false)
        {
            DFS(adj, v, st, visited);
        }
    }
    st.push(s);
}

stack<int> topologicalSort(vector<int> adj[], int v)
{
    bool visited[v] = {false};
    stack<int> st;

    for (int u = 0; u < v; u++)
    {
        if (visited[u] == false)
        {
            DFS(adj, u, st, visited);
        }
    }
    return st;
}

vector<int> shortestPath(vector<int> adj[], int v)
{
    //    let source is 0
    vector<int> dist(v, INT_MAX);
    dist[0] = 0;

    stack<int> st = topologicalSort(adj, v);

    while (st.empty() == false)
    {
        int u = st.top();
        st.pop();

        cout << u << " " << endl;

        if (dist[u] != INT_MAX)
            for (int v : adj[u])
            {
                if (dist[v] > dist[u] + 1)
                {
                    dist[v] = dist[u] + 1;
                }
            }
    }
    return dist;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);

    cout << "Following is a Topological Sort:\n";
    vector<int> dist = shortestPath(adj, V);
    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}