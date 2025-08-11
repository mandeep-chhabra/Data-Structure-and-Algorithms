#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void deleteNode(Node *del_node)
{
    // code here
    del_node->data = del_node->next->data;
    if (del_node->next->next == NULL)
    {
        delete del_node->next;
        del_node->next = NULL;
    }
    else
    {
        Node *temp = del_node->next;
        del_node->next = del_node->next->next;
        delete temp;
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    Node *del_node = head->next->next;
    deleteNode(del_node);

    cout << "List after deleting node 3: ";
    printList(head);

    return 0;
}
