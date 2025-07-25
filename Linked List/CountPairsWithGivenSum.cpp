#include <iostream>
#include <set>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

void insert(Node *&head, int val)
{
    if (!head)
    {
        head = new Node(val);
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new Node(val);
}

int countPairs(struct Node *head1, struct Node *head2, int x)
{
    set<int> s;
    Node *move1 = head1;
    Node *move2 = head2;
    int count = 0;

    while (move1 != NULL)
    {
        s.insert(x - move1->data);
        move1 = move1->next;
    }

    while (move2 != NULL)
    {
        if (s.find(move2->data) != s.end())
        {
            count++;
        }
        move2 = move2->next;
    }
    return count;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    // Example 1
    insert(head1, 1);
    insert(head1, 2);
    insert(head1, 3);

    insert(head2, 3);
    insert(head2, 4);
    insert(head2, 5);

    int x = 6;

    cout << "Linked List 1: ";
    printList(head1);
    cout << "Linked List 2: ";
    printList(head2);
    cout << "Count of pairs with sum " << x << ": " << countPairs(head1, head2, x) << endl;

    return 0;
}
