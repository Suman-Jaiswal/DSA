#include <bits/stdc++.h>
using namespace std;
bool palindrome(string &str, int s, int e)
{
    if (str[s] != str[e])
        return false;
    if (s >= e)
    {
        return true;
    }
    return palindrome(str, s + 1, e - 1);
}
int main()
{
    string n1;
    cin >> n1;
    int l = n1.length();
    cout << palindrome(n1, 0, l - 1);
    return 0;
}