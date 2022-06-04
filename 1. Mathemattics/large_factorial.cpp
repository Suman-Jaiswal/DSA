#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void multiply(vector<int> &arr, int x)
{
    int carry = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int product = arr[i] * x + carry;
        arr[i] = product % 10;
        carry = product / 10;
    }
    while (carry)
    {
        arr.push_back(carry % 10);
        carry /= 10;
    }
}

string factorial(int A)
{
    vector<int> arr(1, 1);
    string s = "";
    for (int i = 2; i <= A; i++)
    {
        multiply(arr, i);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        s += to_string(arr[arr.size() - i - 1]);
    }
    return s;
}

int main()
{
    int n;
    cin >> n;

    cout << factorial(n);

    return 0;
}