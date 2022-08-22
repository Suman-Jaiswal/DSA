#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
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
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);

    head->next = temp1;
    temp1->prev = head;

    temp1->next = temp2;
    temp2->prev = temp1;

    traverseRec(head);

    return 0;
}