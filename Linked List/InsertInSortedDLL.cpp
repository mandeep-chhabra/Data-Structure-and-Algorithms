#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *sortedInsert(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == nullptr)
    {
        return temp;
    }

    Node *move = head;
    while (move != nullptr && move->data < x)
    {
        move = move->next;
    }

    if (move == nullptr)
    {
        Node *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = temp;
        temp->prev = last;
        return head;
    }

    if (move == head)
    {
        temp->next = head;
        head->prev = temp;
        return temp;
    }

    temp->prev = move->prev;
    temp->next = move;
    move->prev->next = temp;
    move->prev = temp;

    return head;
}

int main()
{
    Node *head = new Node(2);
    head->next = new Node(5);
    head->next->prev = head;
    head->next->next = new Node(8);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(10);
    head->next->next->next->prev = head->next->next;

    cout << "Original sorted doubly-linked list: ";
    printList(head);

    int valueToInsert = 7;
    Node *newHead = sortedInsert(head, valueToInsert);
    cout << "After inserting " << valueToInsert << ": ";
    printList(newHead);

    valueToInsert = 1;
    newHead = sortedInsert(newHead, valueToInsert);
    cout << "After inserting " << valueToInsert << ": ";
    printList(newHead);

    valueToInsert = 12;
    newHead = sortedInsert(newHead, valueToInsert);
    cout << "After inserting " << valueToInsert << ": ";
    printList(newHead);

    return 0;
}
