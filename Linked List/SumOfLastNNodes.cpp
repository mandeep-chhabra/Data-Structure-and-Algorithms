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

int sumOfLastN_Nodes(struct Node *head, int n)
{
    Node *move = head;
    int count = 0;
    while (move != NULL)
    {
        count++;
        move = move->next;
    }
    move = head;
    while (count != n)
    {
        count--;
        move = move->next;
    }
    int sum = 0;
    while (count > 0)
    {
        sum += move->data;
        count--;
        move = move->next;
    }
    return sum;
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

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 3;
    Node *head = createList(arr, sizeof(arr) / sizeof(arr[0]));

    int result = sumOfLastN_Nodes(head, n);
    cout << "Sum of last " << n << " nodes: " << result << endl;

    return 0;
}
