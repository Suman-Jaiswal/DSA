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

int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + max(height(root->left), height(root->right)));
}

int diameterNaive(Node *root)
{
    if (root == NULL)
        return 0;
    int d1 = 1 + height(root->left) + height(root->right);
    int d2 = diameterNaive(root->left);
    int d3 = diameterNaive(root->right);

    return max(d1, max(d2, d3));
}

int maxDiameter = 0;

int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    int diameter = left + right + 1;
    maxDiameter = max(maxDiameter, diameter);

    return max(left, right) + 1;
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(60);
    root->right->left->left = new Node(50);
    root->right->right->right = new Node(70);

    cout << diameterNaive(root) << endl;
    maxDepth(root);
    cout << maxDiameter << endl;
    return 0;
}