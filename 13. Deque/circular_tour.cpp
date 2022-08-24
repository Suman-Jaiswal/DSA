#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(itr, start, end) for (int itr = start; itr < end; itr++)
#define v1(name, type) vector<type> name
#define v2(name, type, size) vector<type> name(size)
#define v3(name, type, size, fill) vector<type> name(size, fill)
#define mat1(name, type) vector<vector<type>> name
#define mat2(name, type, row, col) vector<vector<type>> name(row, vector<type>(col))
#define mat3(name, type, row, col, fill) vector<vector<type>> name(row, vector<type>(col, fill))

int getStart(int petrol[], int dist[], int n)
{
    deque<int> dq;

    int curr_petrol = 0;

    int ind = 0;
    int d = 0;
    while (d < 2 * n)
    {
        if (dq.size() == n and curr_petrol >= 0)
            break;

        dq.push_back(ind);
        curr_petrol = curr_petrol + petrol[ind] - dist[ind];

        if (curr_petrol < 0)
        {
            while (!dq.empty() and curr_petrol < 0)
            {
                curr_petrol = curr_petrol - (petrol[dq.front()] - dist[dq.front()]);
                dq.pop_front();
            }
        }

        ind = (ind + 1) % n;
    }
    if (dq.size() == n and curr_petrol >= 0)
    {
        return dq.front();
    }
    return -1;
}

int getIndex(int petrol[], int dist[], int n)
{
    int currp = 0, prevp = 0, start = 0;

    for (int i = 0; i < n; i++)
    {
        currp += petrol[i] - dist[i];
        if (currp < 0)
        {
            start = i + 1;
            prevp += currp;
            currp = 0;
        }
    }
    return (currp + prevp) >= 0 ? (start) : -1;
}

int main()
{
    int petrol[] = {50, 10, 60, 100};
    int dist[] = {30, 20, 100, 10};

    int n = 4;

    cout << getIndex(petrol, dist, n);
    return 0;
}