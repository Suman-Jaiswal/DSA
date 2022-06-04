#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void permutate(string s, int i = 0)
{
    if (i == s.length() - 1)
        cout << s << " ";
    for (int j = i; j < s.length(); j++)
    {
        swap(s[i], s[j]);
        permutate(s, i + 1);
        swap(s[i], s[j]);
    }
}

int main()
{
    string s = "ABCD";

    permutate(s);

    return 0;
}