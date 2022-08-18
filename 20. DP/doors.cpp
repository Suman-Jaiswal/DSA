#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(itr, start, end) for (int itr = start; itr < end; itr++)
#define v1(name, type) vector<type> name
#define v2(name, type, size) vector<type> name(size)
#define v3(name, type, size, fill) vector<type> name(size, fill)
#define mat1(name, type) vector<vector<type>> name
#define mat2(name, type, row, col) vector<vector<type>> name(row, vector<type>(col))
#define mat3(name, type, row, col, fill) vector<vector<type>> name(row, vector<type>(col, fill))

int main()
{
    int n = 100;
    bool doors[n + 1] = {0};

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = i; j < n + 1; j += i)
        {
            doors[j] = !doors[j];
        }
    }
    int res = 0;
    for (int i = 1; i < n + 1; i++)
    {
        res += doors[i];
    }
    cout << res;
    return 0;
}