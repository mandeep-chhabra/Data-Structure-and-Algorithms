#include <iostream>
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

// Function to print k-th node from the end
void KthNodeFromLast(Node *head, int k)
{
    Node *temp = head;
    int count = 0;

    // Count the number of nodes
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    // If k is more than the number of nodes
    if (k > count)
    {
        cout << "-1" << endl;
        return;
    }

    // Find (count - k)-th node from beginning
    int target = count - k;
    temp = head;
    while (target > 0)
    {
        temp = temp->next;
        target--;
    }

    cout << temp->data << endl;
}

int main()
{
    // Creating the singly linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 3;

    KthNodeFromLast(head, k); // Output should be 3

    return 0;
}
