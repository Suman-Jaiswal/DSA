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

bool isCSum(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL and root->right == NULL)
        return true;

    int sum = 0;

    if (root->left != NULL)
        sum += root->left->key;
    if (root->right != NULL)
        sum += root->right->key;

    return (sum == root->key and isCSum(root->left) and isCSum(root->right));
}

int main()
{

    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->right->left = new Node(3);
    root->right->right = new Node(9);

    cout << isCSum(root);
}