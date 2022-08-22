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

Node *insertPos(Node *head, int pos, int data)
{
    Node *temp = new Node(data);
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for (int i = 1; i < pos - 1; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
        return head;

    temp->next = curr->next;
    curr->next = temp;
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head = insertPos(head, 3, 50);
    return 0;
}