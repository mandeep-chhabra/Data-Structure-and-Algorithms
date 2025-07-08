#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find the celebrity
int celebrity(vector<vector<int>> &mat)
{
    stack<int> st;
    int n = mat.size();

    // Push all people onto the stack
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    // Eliminate non-celebrities
    while (st.size() > 1)
    {
        int p1 = st.top();
        st.pop();
        int p2 = st.top();
        st.pop();

        if (mat[p1][p2] == 1)
        {
            st.push(p2); // p1 knows p2 -> p1 can't be celeb
        }
        else
        {
            st.push(p1); // p1 doesn't know p2 -> p2 can't be celeb
        }
    }

    int potential = st.top();

    // Verify if the potential candidate is a celebrity
    for (int i = 0; i < n; i++)
    {
        if (i == potential)
            continue;
        if (mat[potential][i] == 1 || mat[i][potential] == 0)
            return -1;
    }

    return potential;
}

// Main function to test the celebrity function
int main()
{
    int n;
    cout << "Enter number of people: ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter the relationship matrix (0 or 1):\n";
    // Input: mat[i][j] = 1 means person i knows person j
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    int result = celebrity(mat);

    if (result == -1)
        cout << "No celebrity found.\n";
    else
        cout << "Celebrity is person at index: " << result << endl;

    return 0;
}
