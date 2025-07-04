#include <iostream>
#include <stack>
using namespace std;

void insertAtBottomHelper(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottomHelper(st, x);
    st.push(temp);
}

stack<int> insertAtBottom(stack<int> st, int x)
{
    insertAtBottomHelper(st, x);
    return st;
}

void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Original Stack (top to bottom): ";
    printStack(st);

    st = insertAtBottom(st, 5);

    cout << "Stack after inserting 5 at the bottom: ";
    printStack(st);

    return 0;
}
