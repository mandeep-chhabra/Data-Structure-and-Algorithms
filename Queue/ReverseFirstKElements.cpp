#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse the first k elements of the queue
queue<int> reverseFirstK(queue<int> q, int k)
{
    if (k > q.size())
        return q;

    stack<int> st;

    // Push the first k elements into the stack
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // Enqueue the stack elements at the back of the queue
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // Move the remaining elements (n-k) to the back to maintain order
    int n = q.size();
    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }

    return q;
}

// Main function to test the reverseFirstK function
int main()
{
    queue<int> q;
    int n, k;

    cout << "Enter number of elements in queue: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    cout << "Enter value of k: ";
    cin >> k;

    queue<int> result = reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements:\n";
    while (!result.empty())
    {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}
