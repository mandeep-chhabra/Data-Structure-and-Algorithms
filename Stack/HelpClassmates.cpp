#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> help_classmate(vector<int> arr, int n)
{
    stack<int> st;
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }
        res[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter marks: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> result = help_classmate(arr, n);

    cout << "Helped classmate scores: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
