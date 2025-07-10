#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> leftSmaller(vector<int> arr)
{
    vector<int> ans;
    stack<int> st;

    for (auto it : arr)
    {
        while (!st.empty() && st.top() >= it)
        {
            st.pop();
        }

        if (st.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(st.top());
        }

        st.push(it);
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = leftSmaller(arr);

    cout << "Nearest smaller to left: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
