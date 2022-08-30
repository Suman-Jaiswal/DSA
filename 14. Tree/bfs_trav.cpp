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

void bfs(Node *root)
{

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        cout << node->key << " ";

        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

void bfsLinebyLine(Node *root)
{

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            Node *node = q.front();
            q.pop();

            cout << node->key << " ";

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    bfsLinebyLine(root);

    return 0;
}