#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPalin(string s, int start, int end)
{

    if (start >= end)
        return 1;

    return (s[start] == s[end]) && isPalin(s, start + 1, end - 1);
}

int main()
{
    string s;
    cin >> s;

    cout << isPalin(s, 0, s.length() - 1);

    return 0;
}