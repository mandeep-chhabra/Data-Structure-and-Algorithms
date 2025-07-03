#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverse(const string &S)
{
    stack<char> st;
    string result = "";

    for (char it : S)
    {
        st.push(it);
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    string reversed = reverse(input);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
