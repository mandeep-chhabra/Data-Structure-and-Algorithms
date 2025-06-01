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

// Function to insert at head
void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    if (head != nullptr)
    {
        head->prev = newNode;
    }
    head = newNode;
}

// Function to insert at tail
void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Function to insert at k-th position (1-based indexing)
void insertAtPosition(Node *&head, int value, int k)
{
    if (k < 1)
        return;

    if (k == 1)
    {
        insertAtHead(head, value);
        return;
    }

    Node *newNode = new Node(value);
    Node *current = head;
    int count = 1;

    while (current != nullptr && count < k - 1)
    {
        current = current->next;
        count++;
    }

    if (current == nullptr)
    {
        insertAtTail(head, value);
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != nullptr)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
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
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    cout << "Original list: ";
    printLinkedList(head);

    // Insert at head
    insertAtHead(head, 0);
    cout << "\nAfter inserting 0 at head: ";
    printLinkedList(head);

    // Insert at tail
    insertAtTail(head, 5);
    cout << "After inserting 5 at tail: ";
    printLinkedList(head);

    // Insert at position 3 (value 10)
    insertAtPosition(head, 10, 3);
    cout << "After inserting 10 at position 3: ";
    printLinkedList(head);

    return 0;
}