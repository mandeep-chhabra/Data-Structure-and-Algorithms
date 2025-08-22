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

struct Node *mergeResult(Node *node1, Node *node2)
{
    Node *curr = nullptr;
    while (node1 && node2)
    {
        if (node1->data <= node2->data)
        {
            Node *temp = node1;
            node1 = node1->next;
            temp->next = curr;
            curr = temp;
        }
        else
        {
            Node *temp = node2;
            node2 = node2->next;
            temp->next = curr;
            curr = temp;
        }
    }

    while (node1)
    {
        Node *temp = node1;
        node1 = node1->next;
        temp->next = curr;
        curr = temp;
    }

    while (node2)
    {
        Node *temp = node2;
        node2 = node2->next;
        temp->next = curr;
        curr = temp;
    }

    return curr;
}

int main()
{
    int size1, size2;
    cout << "Enter the number of elements for the first sorted list: ";
    cin >> size1;

    Node *head1 = nullptr;
    Node *tail1 = nullptr;
    cout << "Enter the elements: ";
    for (int i = 0; i < size1; ++i)
    {
        int val;
        cin >> val;
        if (!head1)
        {
            head1 = new Node(val);
            tail1 = head1;
        }
        else
        {
            tail1->next = new Node(val);
            tail1 = tail1->next;
        }
    }

    cout << "Enter the number of elements for the second sorted list: ";
    cin >> size2;

    Node *head2 = nullptr;
    Node *tail2 = nullptr;
    cout << "Enter the elements: ";
    for (int i = 0; i < size2; ++i)
    {
        int val;
        cin >> val;
        if (!head2)
        {
            head2 = new Node(val);
            tail2 = head2;
        }
        else
        {
            tail2->next = new Node(val);
            tail2 = tail2->next;
        }
    }

    Node *mergedList = mergeResult(head1, head2);

    cout << "Merged list in descending order: ";
    printList(mergedList);

    return 0;
}