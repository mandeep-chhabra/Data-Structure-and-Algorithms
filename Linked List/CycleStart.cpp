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

Node *createListWithCycle(int n, int cycleStartPos)
{
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *cycleStartNode = nullptr;

    for (int i = 1; i <= n; ++i)
    {
        Node *newNode = new Node(i);
        if (!head)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        if (i == cycleStartPos)
        {
            cycleStartNode = newNode;
        }
    }
    if (cycleStartPos > 0 && cycleStartPos <= n)
    {
        tail->next = cycleStartNode;
    }
    return head;
}

int cycleStart(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow->data;
        }
    }
    return -1;
}

int main()
{
    Node *listWithCycle = createListWithCycle(5, 3);
    int resultWithCycle = cycleStart(listWithCycle);

    if (resultWithCycle != -1)
    {
        cout << "Cycle detected. The starting node has data: " << resultWithCycle << endl;
    }
    else
    {
        cout << "No cycle detected in the first list." << endl;
    }

    Node *listWithoutCycle = createListWithCycle(5, 0);
    int resultWithoutCycle = cycleStart(listWithoutCycle);

    if (resultWithoutCycle != -1)
    {
        cout << "Cycle detected. The starting node has data: " << resultWithoutCycle << endl;
    }
    else
    {
        cout << "No cycle detected in the second list." << endl;
    }

    return 0;
}