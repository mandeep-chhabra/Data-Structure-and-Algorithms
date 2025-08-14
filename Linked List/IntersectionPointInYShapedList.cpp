#include <iostream>
#include <unordered_set>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *intersectPoint(Node *head1, Node *head2)
{
    unordered_set<Node *> st;
    while (head1 != nullptr)
    {
        st.insert(head1);
        head1 = head1->next;
    }
    while (head2 != nullptr)
    {
        if (st.find(head2) != st.end())
        {
            return head2;
        }
        head2 = head2->next;
    }
    return nullptr;
}

void createIntersection(Node *head1, Node *head2, int intersectValue)
{
    Node *temp1 = head1;
    while (temp1->next != nullptr)
    {
        temp1 = temp1->next;
    }

    Node *temp2 = head2;
    while (temp2->next != nullptr)
    {
        temp2 = temp2->next;
    }

    Node *intersectionNode = new Node(intersectValue);
    temp1->next = intersectionNode;
    temp2->next = intersectionNode;
}

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

int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node *head2 = new Node(4);
    head2->next = new Node(5);

    createIntersection(head1, head2, 9);
    head1->next->next->next->next = new Node(10);

    cout << "First linked list: ";
    printList(head1);

    cout << "Second linked list: ";
    printList(head2);

    Node *intersection = intersectPoint(head1, head2);
    if (intersection != nullptr)
    {
        cout << "Intersection point data: " << intersection->data << endl;
    }
    else
    {
        cout << "No intersection point found." << endl;
    }

    return 0;
}