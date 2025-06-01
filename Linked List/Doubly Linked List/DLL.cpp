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

Node *arrayToDLL(int arr[], int n)
{
    if (n == 0)
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *current = head;

    for (int i = 1; i < n; i++)
    {
        Node *newNode = new Node(arr[i]);
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }
    return head;
}

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
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = arrayToDLL(arr, n);

    cout << "Linked List: ";
    printLinkedList(head);

    return 0;
}