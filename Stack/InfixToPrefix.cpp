#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string reverseAndSwapBrackets(const string &s)
{
    string res = s;
    int n = res.size();
    reverse(res.begin(), res.end());
    for (int i = 0; i < n; ++i)
    {
        if (res[i] == '(')
            res[i] = ')';
        else if (res[i] == ')')
            res[i] = '(';
    }
    return res;
}

string infixToPrefix(string s)
{
    stack<char> st;
    s = reverseAndSwapBrackets(s);
    string result = "";

    for (char it : s)
    {
        if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z') || (it >= '0' && it <= '9'))
        {
            result += it;
        }
        else
        {
            if (it == '(')
            {
                st.push(it);
            }
            else if (it == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop();
            }
            else
            {
                while (!st.empty() && prec(it) < prec(st.top()))
                {
                    result += st.top();
                    st.pop();
                }
                st.push(it);
            }
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
