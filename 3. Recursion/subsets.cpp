#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void subsets(string s, string current, int index)
{
    if (index == s.length())
    {
        cout << current << ", ";
        return;
    }

    subsets(s, current, index + 1);
    subsets(s, current + s[index], index + 1);
}

int main()
{
    string s;
    cin >> s;
    string currrent = "";
    int index = 0;
    subsets(s, currrent, index);

    return 0;
}