#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(vector<int> adj[], int v, int dist[])
{
    dist[0] = 0;
    queue<int> q;
    int visited[v] = {false};
    q.push(0);
    visited[0] = true;

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        for (int x : adj[u])
        {
            if (!visited[x])
            {
                dist[x] = dist[u] + 1;
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main()
{
    int v = 5;
    vector<int> adj[v];
    int dist[v] = {INFINITY};

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(2);
    adj[4].push_back(3);

    solve(adj, v, dist);

    return 0;
}