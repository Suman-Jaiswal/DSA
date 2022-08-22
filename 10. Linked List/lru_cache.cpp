#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int k, int v)
    {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
public:
    unordered_map<int, Node *> map;
    int capacity, count;
    Node *head, *tail;

    LRUCache(int c)
    {
        capacity = c;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        head->prev = NULL;
        tail->next = NULL;
        count = 0;
    }

    void deleteNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    void addToHead(Node *node)
    {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    int get(int key)
    {
        if (map[key] != NULL)
        {
            Node *node = map[key];
            int res = node->value;
            deleteNode(node);
            addToHead(node);
            return res;
        }
        return -1;
    }

    void set(int key, int value)
    {
        if (map[key] != NULL)
        {
            Node *node = map[key];
            node->value = value;
            deleteNode(node);
            addToHead(node);
        }
        else
        {
            Node *node = new Node(key, value);
            map[key] = node;
            if (count < capacity)
            {
                count++;
                addToHead(node);
            }
            else
            {
                map.erase(tail->prev->key);
                deleteNode(tail->prev);
                addToHead(node);
            }
        }
    }
};

int main()
{
    {

        LRUCache cache(2);

        // it will store a key (1) with value
        // 10 in the cache.
        cache.set(1, 10);

        // it will store a key (2) with value 20 in the cache.
        cache.set(2, 20);
        cout << "Value for the key: 1 is " << cache.get(1) << endl; // returns 10

        // removing key 2 and store a key (3) with value 30 in the cache.
        cache.set(3, 30);

        cout << "Value for the key: 2 is " << cache.get(2) << endl; // returns -1 (not found)

        // removing key 1 and store a key (4) with value 40 in the cache.
        cache.set(4, 40);
        cout << "Value for the key: 1 is " << cache.get(1) << endl; // returns -1 (not found)
        cout << "Value for the key: 3 is " << cache.get(3) << endl; // returns 30
        cout << "Value for the key: 4 is " << cache.get(4) << endl; // return 40

        return 0;
    }
}