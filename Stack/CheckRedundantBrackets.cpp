#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check for redundant brackets
int checkRedundancy(string s)
{
    stack<char> st;

    for (char it : s)
    {
        if (it == '(' || it == '+' || it == '-' || it == '*' || it == '/')
        {
            st.push(it);
        }
        else if (it == ')')
        {
            bool hasOperator = false;

            while (!st.empty() && st.top() != '(')
            {
                char top = st.top();
                st.pop();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    hasOperator = true;
                }
            }

            if (!st.empty())
                st.pop(); // pop the '('

            if (!hasOperator)
            {
                return 1; // Redundant bracket found
            }
        }
    }

    return 0; // No redundancy
}

int main()
{
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (checkRedundancy(expr))
    {
        cout << "Redundant brackets found." << endl;
    }
    else
    {
        cout << "No redundant brackets." << endl;
    }

    return 0;
}
