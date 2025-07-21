#include <iostream>

// Definition for a singly-linked list node.
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *sortedInsert(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        newNode->next = newNode;
        return newNode;
    }
    if (data <= head->data)
    {
        Node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
        return newNode;
    }
    Node *current = head;
    do
    {
        current = current->next;
    } while (current->next != head && data > current->next->data);
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

void printList(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    Node *current = head;
    do
    {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}

int main()
{
    Node *head = nullptr;
    head = sortedInsert(head, 10);
    head = sortedInsert(head, 20);
    head = sortedInsert(head, 5);
    head = sortedInsert(head, 15);
    head = sortedInsert(head, 25);
    head = sortedInsert(head, 1);
    head = sortedInsert(head, 30);
    printList(head);
    return 0;
}