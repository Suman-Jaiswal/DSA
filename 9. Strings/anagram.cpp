#include <bits/stdc++.h>
using namespace std;

bool solve(string s1, string s2)
{
    if (s2.length() != s1.length())
        return false;

    int count[26] = {0};
    for (size_t i = 0; i < s1.length(); i++)
    {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }
    for (size_t i = 0; i < 26; i++)
    {
        if (count[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    string s1 = "bbccdd";
    string s2 = "dcbdcb";

    cout << solve(s1, s2);

    return 0;
}