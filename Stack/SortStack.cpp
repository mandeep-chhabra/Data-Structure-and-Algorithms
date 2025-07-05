#include <iostream>
#include <stack>
using namespace std;

class SortedStack
{
public:
    stack<int> s;

    void sort(); // Function to sort the stack
};

void insertSorted(stack<int> &s, int temp)
{
    if (s.empty() || s.top() <= temp)
    {
        s.push(temp);
        return;
    }

    int top = s.top();
    s.pop();
    insertSorted(s, temp);
    s.push(top);
}

void SortedStack::sort()
{
    if (s.empty())
        return;

    int temp = s.top();
    s.pop();

    sort();

    insertSorted(s, temp);
}

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    SortedStack ss;

    ss.s.push(30);
    ss.s.push(10);
    ss.s.push(50);
    ss.s.push(20);
    ss.s.push(40);

    cout << "Original Stack (top to bottom): ";
    printStack(ss.s);

    ss.sort();

    cout << "Sorted Stack (top to bottom): ";
    printStack(ss.s);

    return 0;
}
