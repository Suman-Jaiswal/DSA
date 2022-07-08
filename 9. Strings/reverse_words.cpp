#include <bits/stdc++.h>
using namespace std;

string solve(string s, int n)
{
    string res;
    int i = n - 1, j = n - 1;
    while (j >= 0)
    {
        if (s[j] == ' ')
        {
            string sub = s.substr(j + 1, i - j);
            res += sub + ' ';
            i = j;
            j--;
        }
        else
            j--;
    }
    res += s.substr(j + 1, i - j);
    return res;
}

void reverse(string &s, int l, int h)
{
    while (l <= h)
    {
        swap(s[l], s[h]);
        l++;
        h--;
    }
}

void efficient(string &s, int n)
{
    int i = 0, j = 0;
    while (j < n)
    {
        if (s[j] == ' ')
        {
            reverse(s, i, j - 1);
            i = j + 1;
            j++;
        }
        else
            j++;
    }
    reverse(s, i, n - 1);
    reverse(s, 0, n - 1);
}

int main()
{
    string s = "what is your name?";
    int n = s.length();

    efficient(s, n);
    cout << s;
    cout << endl;
    cout << solve(s, n);

    return 0;
}