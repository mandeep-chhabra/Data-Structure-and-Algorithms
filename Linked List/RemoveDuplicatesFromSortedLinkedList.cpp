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

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *removeDuplicates(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    Node *current = head;

    while (current != nullptr && current->next != nullptr)
    {
        if (current->data == current->next->data)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(2);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;

    printList(head);

    removeDuplicates(head);

    printList(head);
}