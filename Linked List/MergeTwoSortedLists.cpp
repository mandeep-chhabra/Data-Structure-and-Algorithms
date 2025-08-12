#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
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

Node *sortedMerge(Node *head1, Node *head2)
{
    Node *dummy = new Node(-1);
    Node *curr = dummy;

    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data >= head2->data)
        {
            curr->next = head2;
            head2 = head2->next;
        }
        else
        {
            curr->next = head1;
            head1 = head1->next;
        }
        curr = curr->next;
    }

    if (head1 != nullptr)
    {
        curr->next = head1;
    }
    else
    {
        curr->next = head2;
    }

    return dummy->next;
}

int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);

    Node *head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);

    cout << "First linked list: ";
    printList(head1);

    cout << "Second linked list: ";
    printList(head2);

    Node *mergedHead = sortedMerge(head1, head2);

    cout << "Merged sorted linked list: ";
    printList(mergedHead);

    return 0;
}