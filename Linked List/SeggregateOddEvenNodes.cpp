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

Node *divide(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *evenHead = NULL;
    Node *evenTail = NULL;
    Node *oddHead = NULL;
    Node *oddTail = NULL;
    Node *current = head;

    while (current != NULL)
    {
        if (current->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = current;
                evenTail = current;
            }
            else
            {
                evenTail->next = current;
                evenTail = current;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = current;
                oddTail = current;
            }
            else
            {
                oddTail->next = current;
                oddTail = current;
            }
        }
        current = current->next;
    }

    if (evenHead != NULL)
    {
        evenTail->next = oddHead;
        if (oddTail != NULL)
            oddTail->next = NULL;
        return evenHead;
    }
    else
    {
        if (oddTail != NULL)
            oddTail->next = NULL;
        return oddHead;
    }
}

Node *createList(int arr[], int n)
{
    if (n == 0)
        return NULL;
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < n; ++i)
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

    cout << "Original List: ";
    printList(head);

    head = divide(head);

    cout << "After Dividing Even and Odd: ";
    printList(head);

    return 0;
}
