#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack() { top = -1; }
    int pop();
    void push(int);
};

void MyStack::push(int x)
{
    if (top >= 999)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    top++;
    arr[top] = x;
}

int MyStack::pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    int temp = arr[top];
    top--;
    return temp;
}

int main()
{
    MyStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    return 0;
}
