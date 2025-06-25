#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkEqual(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    if (n != m)
        return false;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (mp.find(b[i]) == mp.end())
            return false;
        if (mp[b[i]] == 0)
            return false;

        mp[b[i]]--;
    }
    return true;
}

int main()
{
    int n, x;
    vector<int> a, b;

    cout << "Enter the number of elements in the arrays: ";
    cin >> n;

    cout << "Enter " << n << " elements for array A:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }

    cout << "Enter " << n << " elements for array B:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        b.push_back(x);
    }

    bool isEqual = checkEqual(a, b);

    if (isEqual)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

    return 0;
}
