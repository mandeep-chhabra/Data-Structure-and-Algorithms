#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>
#include <sstream>

using namespace std;

int evaluatePostfix(vector<string> &arr)
{
    stack<int> st;

    for (string it : arr)
    {
        if (isdigit(it[0]) || (it.size() > 1 && it[0] == '-'))
        {
            st.push(stoi(it));
        }
        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            if (it == "+")
                st.push(val2 + val1);
            else if (it == "-")
                st.push(val2 - val1);
            else if (it == "*")
                st.push(val2 * val1);
            else if (it == "/")
                st.push(static_cast<int>(floor(static_cast<double>(val2) / val1)));
            else if (it == "^")
                st.push(static_cast<int>(pow(val2, val1)));
        }
    }
    return st.top();
}

int main()
{
    string inputLine;
    cout << "Enter a postfix expression (space-separated, e.g., 2 3 +): ";
    getline(cin, inputLine);

    stringstream ss(inputLine);
    vector<string> arr;
    string token;
    while (ss >> token)
    {
        arr.push_back(token);
    }

    if (arr.empty())
    {
        cout << "No expression entered." << endl;
        return 1;
    }

    int result = evaluatePostfix(arr);
    cout << "The result of the expression is: " << result << endl;

    return 0;
}