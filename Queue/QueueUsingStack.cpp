#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
    stack<int> s1, s2;

public:
    void push(int B)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(B);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        if (s1.empty())
        {
            return -1;
        }
        int temp = s1.top();
        s1.pop();
        return temp;
    }

    bool isEmpty()
    {
        return s1.empty();
    }

    int front()
    {
        if (s1.empty())
        {
            return -1;
        }
        return s1.top();
    }
};

int main()
{
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    while (!q.isEmpty())
    {
        cout << "Front: " << q.front() << endl;
        cout << "Popped: " << q.pop() << endl;
    }

    cout << "Trying to pop from empty queue: " << q.pop() << endl;

    return 0;
}
