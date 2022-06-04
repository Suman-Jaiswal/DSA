#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void steps(int n, char A, char B, char C)
{
    if (n == 1)
    {
        cout << "move disk" << n << " from " << A << " to " << C << endl;
        return;
    }
    steps(n - 1, A, C, B);
    cout << "move disk" << n << " from " << A << " to " << C << endl;
    steps(n - 1, B, A, C);
}

int main()
{
    int t;
    cin >> t;
    char A = 'A', B = 'B', C = 'C';
    steps(t, A, B, C);

    return 0;
}