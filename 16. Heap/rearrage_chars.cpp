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

string solve(string str)
{
    int n = str.size();
    vector<int> count(26, 0);

    int m = 0;

    for (int i = 0; i < n; i++)
    {
        count[str[i] - 'a']++;
        m = max(m, count[str[i] - 'a']);
    }

    if (m > ((n + 1) / 2))
        return "";

    priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

    for (int i = 0; i < 26; i++)
    {
        if (count[i])
            pq.push({count[i], 'a' + i});
    }

    char curr = '*';
    string res = "";

    while (!pq.empty())
    {
        int k = pq.top().first;
        char c = pq.top().second;
        pq.pop();

        if (curr != c)
        {
            res.push_back(c);
            curr = c;
            if (k > 1)
                pq.push({k - 1, c});
        }
        else
        {
            int kk = pq.top().first;
            char cc = pq.top().second;
            pq.pop();

            res.push_back(cc);
            curr = cc;

            if (kk > 1)
                pq.push({kk - 1, cc});
            pq.push({k, c});
        }
    }
    return res;
}

int main()
{
    string str = "geeksforgeeks";

    cout << solve(str);

    return 0;
}