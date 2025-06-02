#include <iostream>
#include <stack>
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

Node *reverse(Node *head)
{
    // Brute Force Approach
    /*
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    stack<int> st;

    // Initialise the node pointer temp at head
    Node *temp = head;

    // Traverse the doubly linked list via the temp pointer
    while (temp != NULL)
    {
        // insert the data of the current node into the stack
        st.push(temp->data);
        // traverse further
        temp = temp->next;
    }

    // Reinitialise temp to head
    temp = head;

    // Second iteration of the DLL to replace the values
    while (temp != NULL)
    {
        // Replace the value pointed via temp with
        // the value from the top of the stack
        temp->data = st.top();
        // Pop the value from the stack
        st.pop();
        // Traverse further
        temp = temp->next;
    }

    return head;
    */

    // Optimal Approach
    if (head->next == nullptr || head == nullptr)
    {
        return head;
    }
    Node *current = head;
    Node *temp = nullptr;

    while (current != nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr)
    {
        head = temp->prev;
    }

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    head = reverse(head);
    print(head);
}