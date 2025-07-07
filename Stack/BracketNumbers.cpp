#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

vector<int> bracketNumbers(string str)
{
    stack<pair<char, int>> st;
    vector<int> result;
    int counter = 0;

    for (char ch : str)
    {
        if (ch == '(')
        {
            ++counter;
            st.push({'(', counter});
            result.push_back(counter);
        }
        else if (ch == ')')
        {
            if (!st.empty())
            {
                result.push_back(st.top().second);
                st.pop();
            }
            else
            {
                result.push_back(0); // optional: for unbalanced ')'
            }
        }
    }

    return result;
}

int main()
{
    string str;
    cout << "Enter a string with brackets: ";
    cin >> str;

    vector<int> result = bracketNumbers(str);

    cout << "Bracket numbers: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
