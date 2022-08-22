#include <bits/stdc++.h>
using namespace std;

void printPrevGreater(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout << -1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false and s.top() <= arr[i])
        {
            s.pop();
        }
        if (s.empty())
            cout << -1 << " ";
        else
            cout << s.top() << " ";

        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = {20, 30, 10, 5, 15};
    int n = 5;
    printPrevGreater(arr, n);
    return 0;
}
