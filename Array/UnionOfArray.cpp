#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findUnion(vector<int> &a, vector<int> &b)
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

    int unionSize = findUnion(a, b);
    cout << "Number of distinct elements in the union: " << unionSize << endl;

    return 0;
}
