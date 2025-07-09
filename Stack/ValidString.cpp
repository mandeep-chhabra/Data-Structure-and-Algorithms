#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (auto it : s)
    {
        if (st.empty() && it == '1')
            return false;
        if (it == '0')
        {
            st.push(it);
        }
        else
        {
            st.pop();
        }
    }
    if (st.empty())
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        string s = "";
        for (int j = 0; j < len; j++)
        {
            char c;
            cin >> c;
            s += c;
        }
        if (isValid(s))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}