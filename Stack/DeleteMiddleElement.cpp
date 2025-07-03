#include <iostream>
#include <stack>
using namespace std;

void deleteMidHelper(stack<int> &s, int curr, int middle)
{
    if (curr == middle)
    {
        s.pop();
        return;
    }

    int temp = s.top();
    s.pop();
    deleteMidHelper(s, curr + 1, middle);
    s.push(temp);
}

void deleteMid(stack<int> &s)
{
    int totalSize = s.size();
    int middle = (totalSize / 2) + 1; // 1-based index
    deleteMidHelper(s, 1, middle);
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
    stack<int> s;
    int n, x;

    cout << "Enter number of elements in stack: ";
    cin >> n;

    cout << "Enter " << n << " elements (top to bottom):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.push(x);
    }

    cout << "Original stack (top to bottom): ";
    printStack(s);

    deleteMid(s);

    cout << "Stack after deleting middle element: ";
    printStack(s);

    return 0;
}
