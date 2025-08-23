#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int fractional_node(struct Node *head, int k)
{
    int n = 0;
    Node *move = head;
    while (move != nullptr)
    {
        n++;
        move = move->next;
    }
    move = head;
    int idx = (n + k - 1) / k;
    for (int i = 1; i < idx; i++)
    {
        move = move->next;
    }
    return move->data;
}

int main()
{
    Node *head = nullptr;
    int n, val, k;

    cout << "Enter the number of elements for the linked list: ";
    cin >> n;
    cout << "Enter the elements in reverse order: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        push(&head, val);
    }

    cout << "Enter the value for k: ";
    cin >> k;

    if (k <= 0)
    {
        cout << "k must be a positive integer." << endl;
        return 1;
    }

    int result = fractional_node(head, k);
    cout << "The data of the fractional node is: " << result << endl;

    return 0;
}