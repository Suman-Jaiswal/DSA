#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(itr, start, end) for (int itr = start; itr < end; itr++)
#define v1(name, type) vector<type> name
#define v2(name, type, size, fill) vector<type> name(size, fill)
#define mat1(name, type) vector<vector<type>> name
#define mat2(name, type, row, col, fill) vector<vector<type>> name(row, vector<type>(col, fill))

void solve(string s, int i, int l)
{
    if (i == l)
        return;
    char ch = s[i];
    if (ch == 'x')
    {
        solve(s, i + 1, l);
        cout << 'x';
    }
    else
    {
        cout << ch;
        solve(s, i + 1, l);
    }
}

int main()
{
    string s = "sdfegaexsafacxxwxwefeerewex";
    solve(s, 0, s.length());
    return 0;
}
