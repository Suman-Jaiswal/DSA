#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(itr, start, end) for (int itr = start; itr < end; itr++)
#define v1(name, type) vector<type> name
#define v2(name, type, size) vector<type> name(size)
#define v3(name, type, size, fill) vector<type> name(size, fill)
#define mat1(name, type) vector<vector<type>> name
#define mat2(name, type, row, col) vector<vector<type>> name(row, vector<type>(col))
#define mat3(name, type, row, col, fill) vector<vector<type>> name(row, vector<type>(col, fill))

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

void traverseIte(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node *insert(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
        return temp;

    if (head->data >= temp->data)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while (true)
    {
        if ((curr->next == NULL) ||
            (curr->data < temp->data and curr->next->data >= temp->data))
        {
            break;
        }
        curr = curr->next;
    }

    if (curr->next == NULL)
    {
        curr->next = temp;
    }
    else
    {
        temp->next = curr->next;
        curr->next = temp;
    }

    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head = insert(head, 35);

    traverseIte(head);
    return 0;
}