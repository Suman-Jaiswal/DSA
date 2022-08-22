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

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int evaluate(string s)
{

    int n = s.length();
    stack<int> st;

    int l = 0;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == ' ')
        {
            string sub = s.substr(l, i - l);

            if (sub.length() == 1 and isOperator(sub[0]))
            {
                l = i + 1;

                int o2 = st.top();
                st.pop();

                int o1 = st.top();

                st.pop();
                if (sub[0] == '+')
                {
                    int res = o1 + o2;
                    st.push(res);
                }
                if (sub[0] == '-')
                {
                    int res = o1 - o2;
                    st.push(res);
                }
                if (sub[0] == '*')
                {
                    int res = o1 * o2;
                    st.push(res);
                }
                if (sub[0] == '/')
                {
                    int res = o1 / o2;
                    st.push(res);
                }
                if (sub[0] == '^')
                {
                    int res = pow(o1, o2);
                    st.push(res);
                }
            }
            else
            {
                int num = stoi(sub);

                st.push(num);
                l = i + 1;
            }
        }
    }
    int o2 = st.top();
    st.pop();
    int o1 = st.top();
    st.pop();
    if (s[n - 1] == '+')
    {
        int res = o1 + o2;
        st.push(res);
    }
    if (s[n - 1] == '-')
    {
        int res = o1 - o2;
        st.push(res);
    }
    if (s[n - 1] == '*')
    {
        int res = o1 * o2;
        st.push(res);
    }
    if (s[n - 1] == '/')
    {
        int res = o1 / o2;
        st.push(res);
    }
    if (s[n - 1] == '^')
    {
        int res = pow(o1, o2);
        st.push(res);
    }
    return st.top();
}

int main()
{
    string s = "10 2 * 3 5 * + 9 -";
    string s1 = "10 2 2 ^ ^";

    cout << evaluate(s1);

    return 0;
}