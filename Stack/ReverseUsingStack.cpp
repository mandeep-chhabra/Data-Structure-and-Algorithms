#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverse(const string &S)
{
    stack<char> st;

    for (char ch : S)
    {
        st.push(ch);
    }

    string reversed;
    while (!st.empty())
    {
        reversed += st.top();
        st.pop();
    }

    return reversed;
}

int main()
{
    string str = "hello";
    cout << reverse(str);
    return 0;
}
