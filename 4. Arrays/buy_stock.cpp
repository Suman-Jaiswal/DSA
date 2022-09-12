#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int prices[5] = {1, 5, 3, 8, 12};

    int profit = 0, n = 5;

    for (int i = 1; i < n; i++)
    {

        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1];
        }
    }

    cout << profit;

    return 0;
}
