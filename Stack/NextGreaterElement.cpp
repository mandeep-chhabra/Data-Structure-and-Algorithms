#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Function to find the next greater element for each element
vector<int> nextLargerElement(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] >= st.top())
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

        st.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// Main function to test the code
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = nextLargerElement(arr);

    cout << "Next greater elements: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
