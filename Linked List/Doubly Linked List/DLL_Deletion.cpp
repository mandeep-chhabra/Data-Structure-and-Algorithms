#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to delete the head node
Node *deleteHead(Node *head)
{
    if (head == nullptr)
        return nullptr;

    Node *newHead = head->next;
    if (newHead != nullptr)
    {
        newHead->prev = nullptr;
    }
    delete head;
    return newHead;
}

// Function to delete the tail node
Node *deleteTail(Node *head)
{
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->prev->next = nullptr;
    delete current;
    return head;
}

// Function to delete the k-th node (1-based indexing)
Node *deleteAtPosition(Node *head, int k)
{
    if (head == nullptr || k < 1)
        return head;

    if (k == 1)
        return deleteHead(head);

    Node *current = head;
    int count = 1;

    while (current != nullptr && count < k)
    {
        current = current->next;
        count++;
    }

    if (current == nullptr)
        return head; // k is larger than list length

    if (current->next == nullptr)
    {
        return deleteTail(head); // k is the last node
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    return head;
}

// Function to print the list forward
void printLinkedList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    cout << "Original list: ";
    printLinkedList(head);

    // Delete at position 2 (1-based)
    head = deleteAtPosition(head, 2);
    cout << "After deleting at position 2: ";
    printLinkedList(head);

    // Delete head
    head = deleteHead(head);
    cout << "After deleting head: ";
    printLinkedList(head);

    // Delete tail
    head = deleteTail(head);
    cout << "After deleting tail: ";
    printLinkedList(head);

    return 0;
}