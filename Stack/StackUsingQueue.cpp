#include <iostream>
#include <queue>
using namespace std;

class QueueStack
{
    queue<int> q1;

public:
    void push(int x)
    {
        int s = q1.size();
        q1.push(x);
        for (int i = 0; i < s; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop()
    {
        if (q1.empty())
            return -1;
        int temp = q1.front();
        q1.pop();
        return temp;
    }

    bool isEmpty()
    {
        return q1.empty();
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }
};

int main()
{
    QueueStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Pop: " << st.pop() << endl;

    st.push(40);
    cout << "Top: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Pop: " << st.pop() << endl;
    cout << "Pop: " << st.pop() << endl;

    return 0;
}
