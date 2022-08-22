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

string postfix(string s)
{

    unordered_map<char, int> precedence;

    precedence['('] = 0;
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['^'] = 3;

    int n = s.length();
    stack<char> st;
    string pf;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == '(')
            st.push('(');
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                char t = st.top();
                st.pop();
                pf.push_back(t);
            }
            st.pop();
        }
        else if (!isOperator(c))
        {
            pf.push_back(c);
        }
        else
        {
            if (st.empty())
            {
                st.push(c);
            }
            else if (c != '^')
            {
                char t = st.top();
                if (precedence[c] > precedence[t])
                {
                    st.push(c);
                }
                else if (precedence[c] <= precedence[t])
                {
                    while (precedence[c] <= precedence[t] and st.empty() == false)
                    {
                        char t = st.top();
                        st.pop();
                        pf.push_back(t);
                    }
                    st.push(c);
                }
            }
            else
            {
                char t = st.top();
                if (precedence[c] > precedence[t])
                {
                    st.push(c);
                }
                else if (precedence[c] <= precedence[t])
                {
                    while (precedence[c] < precedence[t] and st.empty() == false)
                    {
                        char t = st.top();
                        st.pop();
                        pf.push_back(t);
                    }
                    st.push(c);
                }
            }
        }
    }
    while (st.empty() == false)
    {
        pf.push_back(st.top());
        st.pop();
    }
    return pf;
}

int main()
{
    string s = "a+b/c-d*e";
    string s1 = "(a+b)*c";
    string s2 = "a^b^c";

    cout << postfix(s2);

    return 0;
}