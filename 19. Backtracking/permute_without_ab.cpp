#include <bits/stdc++.h>
using namespace std;

bool isSafe(string str, int l, int i, int r)
{
    if (l != 0 and str[l - 1] == 'A' and str[i] == 'B')
        return false;
    if (l + 1 == r and str[i] == 'A' and str[l] == 'B')
        return false;
    return true;
}

void permute(string str, int l, int r)
{
    if (l == r)
    {
        cout << str << " ";
        return;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            if (isSafe(str, l, i, r))
            {
                swap(str[i], str[l]);
                permute(str, l + 1, r);
                swap(str[i], str[l]);
            }
        }
    }
}

int main()
{

    string str = "ABC";

    permute(str, 0, str.length() - 1);
    return 0;
}