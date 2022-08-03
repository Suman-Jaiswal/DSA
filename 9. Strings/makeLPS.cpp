#include <bits/stdc++.h>
using namespace std;

void makeLPS(string s, int lps[], int n)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

int main()
{
    string s = "aaabaaaac";
    int n = s.length();
    int lps[n];

    makeLPS(s, lps, n);

    for (size_t i = 0; i < n; i++)
    {
        cout << lps[i] << " ";
    }

    return 0;
}