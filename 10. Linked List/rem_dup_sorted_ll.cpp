#include <bits/stdc++.h>
using namespace std;

// Linked list Node
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
Node *removeDuplicates(Node *head)
{
    Node *curr = head;
    if (curr == NULL || curr->next == NULL)
        return curr;

    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        else
            curr = curr->next;
    }
    return head;
}

Node *push(Node *head, int new_data)
{
    Node *new_node = new Node(new_data);
    new_node->next = head;
    head = new_node;
    return head;
}
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *llist = NULL;
    llist = push(llist, 20);
    llist = push(llist, 20);
    llist = push(llist, 13);
    llist = push(llist, 13);
    llist = push(llist, 11);
    llist = push(llist, 11);
    llist = push(llist, 11);
    cout << ("List before removal of duplicates\n");
    printList(llist);
    cout << ("List after removal of elements\n");
    llist = removeDuplicates(llist);
    printList(llist);
}
