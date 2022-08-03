#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define v 4

int primMST(int graph[v][v])
{
    int key[v];
    fill(key, key + v, INT_MAX);
    key[0] = 0;
    bool mSet[v];
    fill(mSet, mSet + v, 0);
    int res = 0;

    for (int count = 0; count < v; count++)
    {
        int u = -1;
        for (int i = 0; i < v; i++)
        {
            if (!mSet[i] and (u == -1 || key[i] < key[u]))
                u = i;
        }
        mSet[u] = true;
        res += key[u];
        for (int i = 0; i < v; i++)
        {
            if (graph[u][i] != 0 and mSet[i] == false)
                key[i] = min(graph[u][i], key[i]);
        }
    }
    return res;
}

int main()
{
    int graph[4][4] = {
        {0, 5, 8, 0},
        {5, 0, 10, 15},
        {8, 10, 0, 20},
        {0, 15, 20, 0},
    };

    cout << primMST(graph);

    return 0;
}