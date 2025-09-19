#include <iostream>
#include <string>
#include <stack>

using namespace std;

int minParentheses(string &s)
{
    int count = 0;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push('(');
        }
        else
        {
            if (st.empty())
            {
                count++;
            }
            else
            {
                st.pop();
            }
        }
    }

    while (!st.empty())
    {
        count++;
        st.pop();
    }
    return count;
}

int main()
{
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;

    int result = minParentheses(s);

    cout << "Minimum parentheses to add for validity: " << result << endl;

    return 0;
}