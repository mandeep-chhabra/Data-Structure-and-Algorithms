#include <iostream>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *intersectPoint(Node *head1, Node *head2)
{
    //  Code Here
    unordered_set<Node *> st;
    while (head1 != NULL)
    {
        st.insert(head1);
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        if (st.find(head2) != st.end())
            return head2;
        head2 = head2->next;
    }
    return NULL;
}

int main()
{
    // creation of first list: 10 -> 15 -> 30
    Node *head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(30);

    // creation of second list: 3 -> 6 -> 9 -> 15 -> 30
    Node *head2 = new Node(3);
    head2->next = new Node(6);
    head2->next->next = new Node(9);

    // 15 is the intersection point
    head2->next->next->next = head1->next;

    Node *intersectionPoint = intersectPoint(head1, head2);

    if (intersectionPoint == nullptr)
        cout << "-1";
    else
        cout << intersectionPoint->data << endl;

    return 0;
}
