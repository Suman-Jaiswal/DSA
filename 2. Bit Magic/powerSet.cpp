#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    for (int i = 0; i < pow(2, n); i++)
    {
        string sub = "";
        for (size_t j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                sub.push_back(s[j]);
            }
        }
        cout << sub << endl;
    }

    return 0;
}