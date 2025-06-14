#include <iostream>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;

    StackNode(int x)
    {
        data = x;
        next = NULL;
    }
};

class MyStack
{
private:
    StackNode *top;

public:
    MyStack() { top = NULL; }

    void push(int x)
    {
        StackNode *temp = new StackNode(x);
        temp->next = top;
        top = temp;
    }

    int pop()
    {
        if (top == NULL)
            return -1;
        int temp = top->data;
        StackNode *toDelete = top;
        top = top->next;
        delete toDelete;
        return temp;
    }
};

int main()
{
    MyStack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << "Popped: " << stack.pop() << endl; // 15
    cout << "Popped: " << stack.pop() << endl; // 10
    cout << "Popped: " << stack.pop() << endl; // 5
    cout << "Popped: " << stack.pop() << endl; // -1 (Empty)

    return 0;
}
