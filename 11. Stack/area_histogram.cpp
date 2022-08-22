#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int arr[], int n)
{
    stack<int> s;
    int ps[n], ns[n];

    int res = 0;

    s.push(0);

    for (int i = 0; i < n; i++)
    {
        while (s.empty() == false and arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        int pse = s.empty() ? -1 : s.top();
        ps[i] = pse;
        s.push(i);
    }

    while (s.empty() == false)
    {
        s.pop();
    }

    s.push(n - 1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (s.empty() == false and arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        int nse = s.empty() ? -1 : s.top();
        ns[i] = nse;
        s.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        int area = (ns[i] - ps[i] - 1) * arr[i];
        res = max(res, area);
    }

    return res;
}

int getMaxAreaEff(int arr[], int n)
{
    stack<int> s;
    int res = 0;
    int tp;
    int curr;

    for (int i = 0; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] >= arr[i])
        {
            tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            res = max(res, curr);
        }
        s.push(i);
    }
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
        res = max(res, curr);
    }

    return res;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    int n = 7;
    cout << "Maximum Area: " << getMaxArea(arr, n);
    return 0;
}
