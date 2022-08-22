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
    bool visited;
    Node *next;

    Node(int x)
    {
        data = x;
        visited = false;
        next = NULL;
    }
};

Node *push(Node *head, int data)
{

    Node *newNode = new Node(data);
    if (head == NULL)
        return newNode;

    Node *curr = head;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = newNode;
    return head;
}

bool detectLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return false;

    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->visited)
            return true;
        curr->visited = true;
        curr = curr->next;
    }
    return false;
}

bool isLoopHash(Node *head)
{
    unordered_set<Node *> s;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        if (s.find(curr) != s.end())
            return true;
        s.insert(curr);
    }
    return false;
}

bool isLoopFloyd(Node *head)
{
    Node *slow_p = head, *fast_p = head;

    while (fast_p != NULL && fast_p->next != NULL)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    Node *head = new Node(1);
    head = push(head, 5);
    head = push(head, 6);
    head = push(head, 10);
    head = push(head, 17);

    Node *curr = head;
    Node *end = head->next;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = end;

    cout << detectLoop(head);

    return 0;
}