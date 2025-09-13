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
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

Node *reverseList(Node *head)
{
    Node *curr = head, *prev = nullptr, *next;

    while (curr != nullptr)
    {
        next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

void reorderList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *secondHalf = reverseList(slow->next);
    slow->next = nullptr;

    Node *move = head;

    while (secondHalf != nullptr)
    {
        Node *temp = secondHalf->next;
        secondHalf->next = move->next;
        move->next = secondHalf;
        move = move->next->next;
        secondHalf = temp;
    }
}

Node *buildList()
{
    int n, val;
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0)
        return nullptr;

    Node *head = nullptr;
    Node *tail = nullptr;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        if (!head)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
    return head;
}

int main()
{
    Node *head = buildList();

    if (head == nullptr)
    {
        cout << "Empty list. No reordering needed." << endl;
        return 0;
    }

    cout << "Original list: ";
    printList(head);

    reorderList(head);

    cout << "Reordered list: ";
    printList(head);

    return 0;
}