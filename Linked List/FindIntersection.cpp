#include <iostream>
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

Node *findIntersection(Node *head1, Node *head2)
{
    Node *move1 = head1;
    Node *move2 = head2;
    Node *newHead = nullptr;
    Node *move3 = nullptr;

    while (move1 != nullptr && move2 != nullptr)
    {
        if (move1->data < move2->data)
        {
            move1 = move1->next;
        }
        else if (move1->data > move2->data)
        {
            move2 = move2->next;
        }
        else
        {
            Node *temp = new Node(move1->data);
            if (!newHead)
            {
                newHead = temp;
                move3 = newHead;
            }
            else
            {
                move3->next = temp;
                move3 = move3->next;
            }
            move1 = move1->next;
            move2 = move2->next;
        }
    }

    return newHead;
}

// Utility to print list
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility to insert at end
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
    Node *head1 = nullptr;
    Node *head2 = nullptr;

    // List 1: 1 → 2 → 3 → 4 → 6
    insertAtEnd(head1, 1);
    insertAtEnd(head1, 2);
    insertAtEnd(head1, 3);
    insertAtEnd(head1, 4);
    insertAtEnd(head1, 6);

    // List 2: 2 → 4 → 6 → 8
    insertAtEnd(head2, 2);
    insertAtEnd(head2, 4);
    insertAtEnd(head2, 6);
    insertAtEnd(head2, 8);

    cout << "List 1: ";
    printList(head1);
    cout << "List 2: ";
    printList(head2);

    Node *intersect = findIntersection(head1, head2);

    cout << "Intersection: ";
    printList(intersect);

    return 0;
}
