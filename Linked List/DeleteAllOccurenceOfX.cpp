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

void deleteAllOccurOfX(struct Node **head_ref, int x)
{
    // Write your code here
    Node *temp = *head_ref;

    while (temp != NULL)
    {
        if (temp->data == x)
        {
            Node *toDelete = temp;
            Node *front = temp->prev;
            Node *back = temp->next;

            if (front != NULL)
            {
                front->next = back;
            }
            else
            {
                // Deleting head node
                *head_ref = back;
            }

            if (back != NULL)
            {
                back->prev = front;
            }

            temp = temp->next; // move before deleting
            delete toDelete;
        }
        else
        {
            temp = temp->next;
        }
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;

    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;

    printList(head);

    deleteAllOccurOfX(&head, 2);

    printList(head);
}