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

long long unsigned int decimalValue(Node *head)
{
    long long unsigned int ans = 0;
    long long int M = 1000000007;
    while (head != nullptr)
    {
        ans = ((ans << 1) + head->data) % M;
        head = head->next;
    }
    return ans;
}

int main()
{
    Node *head = nullptr;
    int n, val;

    cout << "Enter the number of binary digits: ";
    cin >> n;
    cout << "Enter the digits (0 or 1) in reverse order: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        push(&head, val);
    }

    long long unsigned int decimal = decimalValue(head);
    cout << "The decimal value of the binary linked list is: " << decimal << endl;

    return 0;
}