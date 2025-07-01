#include <iostream>
#include <map>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *sortLinkedListByDataFrequency(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    map<int, int> freq;
    Node *temp = head;

    while (temp != nullptr)
    {
        freq[temp->data]++;
        temp = temp->next;
    }

    temp = head;
    for (auto it = freq.begin(); it != freq.end(); ++it)
    {
        for (int i = 0; i < it->second; i++)
        {
            temp->data = it->first;
            temp = temp->next;
        }
    }

    return head;
}

int main()
{
    // Create list: 4 -> 2 -> 1 -> 3 -> 2
    Node *head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);

    cout << "Original List: ";
    printList(head);

    head = sortLinkedListByDataFrequency(head);

    cout << "Sorted List by Data: ";
    printList(head);

    return 0;
}
