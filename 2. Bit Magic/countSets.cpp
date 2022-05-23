#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t, count = 0;
    cin >> t;
    while (t > 0)
    {
        // if ((t & 1) == 1)
        // {
        //     //    last is set;
        //     count++;
        // }

        // or

        // count += (t & 1);
        // t >>= 1;

        // or

        t = (t & (t - 1));
        count++;
    }
    cout << count;

    return 0;
}