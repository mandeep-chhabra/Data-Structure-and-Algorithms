#include <iostream>
using namespace std;

// Definition of the Node
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Function to insert a node in sorted order
Node *sortedInsert(Node *head, int key)
{
    Node *temp = new Node(key);

    if (head == NULL || key < head->data)
    {
        temp->next = head;
        return temp;
    }

    Node *current = head;
    while (current->next != NULL && current->next->data < key)
    {
        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;

    return head;
}

// Function to print the linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from an array
Node *createList(int arr[], int n)
{
    if (n == 0)
        return NULL;
    Node *head = new Node(arr[0]);
    Node *tail = head;
    for (int i = 1; i < n; i++)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = createList(arr, n);

    cout << "Original list: ";
    printList(head);

    int key = 25;
    head = sortedInsert(head, key);

    cout << "List after inserting " << key << ": ";
    printList(head);

    return 0;
}
