#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int noOfSteps(int n)
{
    if (n == 1)
        return 1;
    return 2 * noOfSteps(n - 1) + 1;
}

int main()
{
    int t;
    cin >> t;

    cout << noOfSteps(t);

    return 0;
}