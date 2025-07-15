#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
        return NULL;

    unordered_map<int, int> mp;
    Node *move = head;
    mp[head->data] = 1;

    while (move != NULL && move->next != NULL)
    {
        if (mp.find(move->next->data) != mp.end())
        {
            Node *temp = move->next;
            move->next = move->next->next;
            delete temp;
        }
        else
        {
            mp[move->next->data] = 1;
            move = move->next;
        }
    }
    return head;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

int main()
{
    Node *head = nullptr;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 10);
    insertAtEnd(head, 30);
    insertAtEnd(head, 20);
    insertAtEnd(head, 40);

    cout << "Original list: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "After removing duplicates: ";
    printList(head);

    return 0;
}
