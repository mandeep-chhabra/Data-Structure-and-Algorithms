#include <iostream>
#include <stack>

using namespace std;

class Solution
{
private:
    stack<pair<int, int>> st;

public:
    Solution()
    {
        // nothing required here
    }

    // Add an element to the top of Stack
    void push(int x)
    {
        if (st.empty())
        {
            st.push({x, x});
        }
        else
        {
            int currentMin = min(x, st.top().second);
            st.push({x, currentMin});
        }
    }

    // Remove the top element from the Stack
    void pop()
    {
        if (!st.empty())
            st.pop();
    }

    // Returns top element of the Stack
    int peek()
    {
        if (st.empty())
            return -1;
        return st.top().first;
    }

    // Finds minimum element of Stack
    int getMin()
    {
        if (st.empty())
            return -1;
        return st.top().second;
    }
};

int main()
{
    Solution s;
    s.push(5);
    s.push(3);
    s.push(7);
    cout << s.getMin() << endl; // 3
    s.pop();
    cout << s.peek() << endl;   // 3
    cout << s.getMin() << endl; // 3
    s.pop();
    cout << s.getMin() << endl; // 5
}
