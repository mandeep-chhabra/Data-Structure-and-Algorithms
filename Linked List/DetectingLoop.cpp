#include <iostream>
#include <unordered_map>
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
}

void detectLoop(Node *head)
{
    // Brute Force Approach (using HashMap)
    Node *temp = head;
    unordered_map<Node *, int> nodeMap;

    while (temp != NULL)
    {
        if (nodeMap.find(temp) != nodeMap.end())
        {
            cout << "true" << endl;
            return;
        }

        nodeMap[temp] = 1;
        temp = temp->next;
    }

    // Optimal Approach
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "true" << endl;
            return;
        }
    }
    cout << "false" << endl;
}

int main()
{
    // Creating a List with a loop
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    node1->next = node2;
    Node *node3 = new Node(3);
    node2->next = node3;
    Node *node4 = new Node(4);
    node3->next = node4;
    Node *node5 = new Node(5);
    node4->next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node *head = node1;

    detectLoop(head);
}