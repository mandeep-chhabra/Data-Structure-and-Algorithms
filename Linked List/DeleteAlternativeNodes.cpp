#include <iostream>
using namespace std;

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

void deleteAlt(struct Node *head)
{
    Node *move = head;
    while (move != NULL && move->next != NULL)
    {
        Node *temp = move->next;
        move->next = move->next->next;
        delete temp;
        move = move->next;
    }
}

Node *createList(int arr[], int size)
{
    if (size == 0)
        return NULL;
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < size; ++i)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = createList(arr, n);

    cout << "Original list: ";
    printList(head);

    deleteAlt(head);

    cout << "After deleting alternate nodes: ";
    printList(head);

    return 0;
}
