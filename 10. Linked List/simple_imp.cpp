#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void traverseRec(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    traverseRec(head->next);
}
void traverseIte(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    traverseRec(head);

    return 0;
}