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

bool isBST(Node *root, int min, int max)
{
    if (root == NULL)
        return true;

    return (root->key > min && root->key < max &&
            isBST(root->left, min, root->key) && isBST(root->right, root->key, max));
}

// more efficient - inorder trav of every bst is sorted;

bool isBSTEff(Node *root, int prev = INT_MIN)
{
    if (root == NULL)
        return true;
    if (isBSTEff(root->left, prev) == false)
        return false;
    if (root->key <= prev)
        return false;
    prev = root->key;

    return (isBSTEff(root->right, prev));
}

int main()
{

    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "Is BST";
    else
        cout << "Not a BST";

    if (isBSTEff(root))
        cout << "Is BST";
    else
        cout << "Not a BST";

    return 0;
}