#include <bits/stdc++.h>
using namespace std;
#define ll long long int

double getMedian(int a1[], int a2[], int n1, int n2)
{
    int l = 0, r = n1;

    while (l <= r)
    {
        int i1 = (l + r) / 2, i2 = (n1 + n2 + 1) / 2 - i1;
        int min1 = (i1 == n1) ? INT_MAX : a1[i1];
        int max1 = (i1 == 0) ? INT_MIN : a1[i1 - 1];
        int min2 = (i2 == n2) ? INT_MAX : a2[i2];
        int max2 = (i2 == 0) ? INT_MIN : a2[i2 - 1];

        if (max1 <= min2 and max2 <= min1)
        {
            return ((n1 + n2) % 2 == 0) ? (double)(max(max1, max2) + min(min1, min2)) / 2 : max(max1, max2);
        }
        else if (max1 > min2)
            r = i1 - 1;
        else
            l = i1 + 1;
    }
    return 0;
}

int main()
{
    int a1[] = {10, 20, 30}, a2[] = {5, 15, 25, 35, 55};
    int n1 = sizeof(a1) / sizeof(a1[0]), n2 = sizeof(a2) / sizeof(a2[0]);
    cout << getMedian(a1, a2, n1, n2);
    return 0;
}