#include <bits/stdc++.h>
using namespace std;

int solve(string s, int n)
{
    int count[26] = {0};
    for (size_t i = 0; i < n; i++)
    {
        count[s[i] - 'a']++;
    }
    for (size_t i = 0; i < n; i++)
    {
        if (count[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}

int main()
{
    string s = "bcbcbzddyee";
    int n = s.length();

    cout << solve(s, n);

    return 0;
}