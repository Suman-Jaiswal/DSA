#include <bits/stdc++.h>
using namespace std;

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

struct MyStack
{
    Node *head;
    int sz;
    MyStack(int x)
    {
        head = NULL;
        sz = 0;
        push(x);
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        sz++;
    }

    int pop()
    {
        if (head == NULL)
            return INT_MAX;
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        sz--;
        return res;
    }

    int size()
    {
        return sz;
    }

    int peek()
    {
        if (head == NULL)
            return INT_MAX;
        return head->data;
    }

    bool isEmpty()
    {
        return (sz == 0);
    }
};

int main()
{
    MyStack s(5);
    s.push(5);
    s.push(10);
    s.push(20);
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;

    return 0;
}