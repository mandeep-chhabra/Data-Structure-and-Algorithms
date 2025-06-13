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

void print(Node *head)
{
    while (head != nullptr)
    {
        // Print the data in the tail node
        cout << head->data << " ";
        // Move to the next node
        head = head->next;
    }
    cout << endl;
}

Node *removeDuplicates(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *temp = head->next;

    while (temp != NULL)
    {
        if (temp->data == temp->prev->data)
        {
            Node *toDelete = temp;
            temp->prev->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            temp = temp->next;
            delete toDelete;
        }
        else
        {
            temp = temp->next;
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
    head->next->next->next = new Node(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->prev = head->next->next->next;

    print(head);
    head = removeDuplicates(head);
    print(head);
}