#include <iostream>
#include <set>

using namespace std;

// Definition for singly-linked list.
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to print the linked list
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

// Your provided function
Node *findUnion(Node *head1, Node *head2)
{
    set<int> s;

    while (head1 != nullptr && head2 != nullptr)
    {
        s.insert(head1->data);
        s.insert(head2->data);
        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1 != nullptr)
    {
        s.insert(head1->data);
        head1 = head1->next;
    }

    while (head2 != nullptr)
    {
        s.insert(head2->data);
        head2 = head2->next;
    }

    Node *head = new Node(-1);
    Node *curr = head;
    for (auto it : s)
    {
        Node *temp = new Node(it);
        curr->next = temp;
        curr = curr->next;
    }
    return head->next;
}

int main()
{
    // Create the first sorted linked list: 1 -> 2 -> 3 -> 4
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);

    // Create the second sorted linked list: 2 -> 4 -> 6 -> 8
    Node *head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);

    cout << "First linked list: ";
    printList(head1);

    cout << "Second linked list: ";
    printList(head2);

    Node *unionHead = findUnion(head1, head2);

    cout << "Union of the two linked lists: ";
    printList(unionHead);

    return 0;
}