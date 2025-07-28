#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removePair(string s)
{
    stack<char> st;
    for (auto it : s)
    {
        if (!st.empty() && st.top() == it)
            st.pop();
        else
            st.push(it);
    }

    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string input;
    cout << "Enter the string: ";
    cin >> input;

    string result = removePair(input);
    cout << "Resultant string after removing adjacent pairs: " << result << endl;

    return 0;
}
