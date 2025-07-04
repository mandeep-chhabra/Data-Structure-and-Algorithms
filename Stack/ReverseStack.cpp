#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(temp);
}

void Reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int target = st.top();
    st.pop();

    Reverse(st);

    insertAtBottom(st, target);
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
    st.push(40);

    cout << "Original Stack (top to bottom): ";
    printStack(st);

    Reverse(st);

    cout << "Reversed Stack (top to bottom): ";
    printStack(st);

    return 0;
}
