#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate stock span
vector<int> calculateSpan(vector<int> &arr)
{
    vector<int> span;
    stack<pair<int, int>> st;
    int n = arr.size();
    int count;

    for (int i = 0; i < n; i++)
    {
        count = 1;
        while (!st.empty() && st.top().first <= arr[i])
        {
            count += st.top().second;
            st.pop();
        }
        st.push({arr[i], count});
        span.push_back(count);
    }

    return span;
}

// Driver code
int main()
{
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    vector<int> span = calculateSpan(prices);

    cout << "Span values: ";
    for (int val : span)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
