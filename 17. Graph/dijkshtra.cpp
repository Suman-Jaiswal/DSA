#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define v 4

vector<int> dijkshtra(int graph[v][v], int src)
{
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    vector<bool> fin(v, 0);

    for (int count = 0; count < v - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < v; i++)
        {
            if (!fin[i] and (u == -1 || dist[i] < dist[u]))
                u = i;
        }
        fin[u] = true;
        for (int i = 0; i < v; i++)
        {
            if (graph[u][i] != 0 and fin[i] == false)
                dist[i] = min(graph[u][i] + dist[u], dist[i]);
        }
    }
    return dist;
}

int main()
{
    int graph[4][4] = {
        {0, 5, 8, 0},
        {5, 0, 10, 15},
        {8, 10, 0, 20},
        {0, 15, 20, 0},
    };
    vector<int> dist = dijkshtra(graph, 0);
    for (size_t i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}