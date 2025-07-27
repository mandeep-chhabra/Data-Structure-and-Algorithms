#include <iostream>
#include <stack>
#include <set>
using namespace std;

int minLength(string str, int n)
{
    set<string> validPairs = {"12", "21", "34", "43", "56", "65", "78", "87", "09", "90"};
    stack<char> st;

    for (char currentChar : str)
    {
        if (!st.empty())
        {
            string potentialPair;
            potentialPair += st.top();
            potentialPair += currentChar;

            if (validPairs.count(potentialPair))
            {
                st.pop();
            }
            else
            {
                st.push(currentChar);
            }
        }
        else
        {
            st.push(currentChar);
        }
    }
    return st.size();
}

int main()
{
    string input;
    cout << "Enter the string of digits: ";
    cin >> input;

    int result = minLength(input, input.length());
    cout << "Minimum length of string after removals: " << result << endl;

    return 0;
}
