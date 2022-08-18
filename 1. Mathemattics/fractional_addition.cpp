#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(itr, start, end) for (int itr = start; itr < end; itr++)
#define v1(name, type) vector<type> name
#define v2(name, type, size, fill) vector<type> name(size, fill)
#define mat1(name, type) vector<vector<type>> name
#define mat2(name, type, row, col, fill) vector<vector<type>> name(row, vector<type>(col, fill))

int findlcm(int a, int b)
{
    int gcd = __gcd(a, b);
    return (a * b) / gcd;
}

int main()
{
    string s = "1/2+1/5+7/10";

    int l = 0;
    v1(numbers, string);
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == '+')
        {

            numbers.push_back(s.substr(l, i - l));
            l = i + 1;
        }
        if (i == s.length() - 1)
            numbers.push_back(s.substr(l, i - l + 1));
    }

    v1(numer, int);
    v1(denom, int);

    for (size_t i = 0; i < numbers.size(); i++)
    {
        string num = numbers[i];
        int ind;
        for (ind = 0; ind < num.length(); ind++)
        {
            if (num[ind] == '/')
                break;
        }
        int n = stoi(num.substr(0, ind));
        int d = stoi(num.substr(ind + 1, s.length() - ind));
        numer.push_back(n);
        denom.push_back(d);
    }

    int lcm = denom[0];
    for (size_t i = 1; i < numbers.size(); i++)
    {
        lcm = findlcm(lcm, denom[i]);
    }

    int sum = 0;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        int q = lcm / denom[i];
        q *= numer[i];
        sum += q;
    }

    string res = to_string(sum) + "/" + to_string(lcm);
    cout << res;

    return 0;
}