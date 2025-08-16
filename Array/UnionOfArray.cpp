#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void printVector(const vector<int> &vec)
{
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
}

vector<int> findUnion(vector<int> a, vector<int> b)
{
    int n1 = 0, n2 = 0;
    vector<int> ans;
    while (n1 < a.size() && n2 < b.size())
    {
        if (a[n1] <= b[n2])
        {
            if (ans.empty() || ans.back() != a[n1])
            {
                ans.push_back(a[n1]);
            }
            n1++;
        }
        else
        {
            if (ans.empty() || ans.back() != b[n2])
            {
                ans.push_back(b[n2]);
            }
            n2++;
        }
    }

    while (n1 < a.size())
    {
        if (ans.empty() || a[n1] != ans.back())
        {
            ans.push_back(a[n1]);
        }
        n1++;
    }

    while (n2 < b.size())
    {
        if (ans.empty() || b[n2] != ans.back())
        {
            ans.push_back(b[n2]);
        }
        n2++;
    }

    return ans;
}

/* int findUnion(vector<int> &a, vector<int> &b)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < a.size(); i++)
    {
        mp[a[i]]++;
    }
    for (int i = 0; i < b.size(); i++)
    {
        mp[b[i]]++;
    }
    return mp.size();
}
*/

int main()
{
    int n, m, x;
    vector<int> a, b;

    cout << "Enter the number of elements in array A: ";
    cin >> n;
    cout << "Enter " << n << " elements for array A:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }

    cout << "Enter the number of elements in array B: ";
    cin >> m;
    cout << "Enter " << m << " elements for array B:\n";
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        b.push_back(x);
    }

    vector<int> unionArray = findUnion(a, b);
    cout << "Union of arrays: ";
    printVector(unionArray);

    return 0;
}
