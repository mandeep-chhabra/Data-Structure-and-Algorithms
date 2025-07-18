#include <iostream>
using namespace std;

// Node structure
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

long long multiplyTwoLists(Node *first, Node *second)
{
    long long MOD = 1000000007;
    long long num1 = 0, num2 = 0;
    while (first != NULL)
    {
        num1 = (num1 * 10 + first->data) % MOD;
        first = first->next;
    }
    while (second != NULL)
    {
        num2 = (num2 * 10 + second->data) % MOD;
        second = second->next;
    }
    return (num1 * num2) % MOD;
}

Node *createList(string number)
{
    Node *head = new Node(number[0] - '0');
    Node *temp = head;
    for (int i = 1; i < number.length(); i++)
    {
        temp->next = new Node(number[i] - '0');
        temp = temp->next;
    }
    return head;
}

int main()
{
    string num1 = "123";
    string num2 = "45";

    Node *first = createList(num1);
    Node *second = createList(num2);

    long long result = multiplyTwoLists(first, second);
    cout << "Result of multiplication: " << result << endl;

    return 0;
}
