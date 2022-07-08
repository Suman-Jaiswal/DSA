#include <bits/stdc++.h>
using namespace std;

bool solve(string s1, string s2)
{
    if (s2.length() > s1.length())
        return false;
    int i = 0, j = 0;
    while (i < s1.length() and j < s2.length())
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }
    return (j == s2.length());
}

int main()
{
    string s1 = "geeksforgeeks";
    string s2 = "grges";

    cout << solve(s1, s2);

    return 0;
}