#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int isBalanced(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;
    return max(lh, rh) + 1;
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->right = new Node(20);

    if (isBalanced(root))
        cout << "Balanced";
    else
        cout << "Not Balanced";
}