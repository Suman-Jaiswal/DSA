#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int arr[6] = {10, 10, 10, 25, 30, 30}, curr = arr[0], c = 1;

    for (int i = 1; i < 5; i++)
    {
        if (arr[i] == curr)
            c++;
        else
        {
            cout << curr << ": " << c << endl;
            c = 1;
            curr = arr[i];
        }
    }

    if (curr == arr[5])
        cout << curr << ": " << c + 1 << endl;
    else
    {
        cout << arr[5] << ": " << 1;
    }

    return 0;
}