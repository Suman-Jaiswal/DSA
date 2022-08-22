#include <bits/stdc++.h>
using namespace std;

bool matching(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}

bool isBalanced(string str)
{
    stack<char> s;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(str[i]);
            continue;
        }
        if (matching(s.top(), str[i]))
        {
            s.pop();
        }
        else
        {
            s.push(str[i]);
        }
    }
    return (s.empty());
}

int main()
{
    string str = "{()}(())[]";

    if (isBalanced(str))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}
