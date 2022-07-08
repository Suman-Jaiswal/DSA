#include <bits/stdc++.h>
using namespace std;

int solve(string s, int n)
{
    int count[26] = {0};
    char c;
    for (size_t i = 0; i < n; i++)
    {
        if (count[s[i] - 'a'] == 1)
        {
            c = s[i];
            break;
        }
        else
            count[s[i] - 'a']++;
    }
    int index = s.find(c);
    return index ? index : -1;
}

int main()
{
    string s = "abcddee";
    int n = s.length();

    cout << solve(s, n);

    return 0;
}