#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

bool isCircular(Node *head)
{
    if (head == nullptr)
        return true;

    Node *move = head;

    while (move->next != nullptr && move->next != head)
    {
        move = move->next;
    }

    return (move->next == head);
}

Node *createList(int n, bool circular)
{
    if (n <= 0)
        return nullptr;
    Node *head = new Node(1);
    Node *tail = head;
    for (int i = 2; i <= n; ++i)
    {
        tail->next = new Node(i);
        tail = tail->next;
    }
    if (circular)
    {
        tail->next = head;
    }
    return head;
}

int main()
{
    // Test Case 1: Circular List (1 -> 2 -> 3 -> 1)
    Node *circularList = createList(3, true);
    cout << "List 1 (Circular): " << (isCircular(circularList) ? "True" : "False") << endl;

    // Test Case 2: Linear List (1 -> 2 -> 3 -> nullptr)
    Node *linearList = createList(3, false);
    cout << "List 2 (Linear): " << (isCircular(linearList) ? "True" : "False") << endl;

    // Test Case 3: Empty List (per user's logic)
    Node *emptyList = createList(0, false);
    cout << "List 3 (Empty): " << (isCircular(emptyList) ? "True" : "False") << endl;

    return 0;
}