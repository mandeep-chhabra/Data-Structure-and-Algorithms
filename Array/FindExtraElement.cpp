#include <iostream>
#include <vector>
using namespace std;

int findExtra(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int index = n;

    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (mid < b.size() && b[mid] == a[mid])
            left = mid + 1;
        else
        {
            index = mid;
            right = mid - 1;
        }
    }

    return index;
}

int main()
{
    int n, x;
    vector<int> a, b;

    cout << "Enter the size of array A (with one extra element): ";
    cin >> n;

    cout << "Enter " << n << " sorted elements for array A:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }

    cout << "Enter " << n - 1 << " sorted elements for array B:\n";
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        b.push_back(x);
    }

    int extraIndex = findExtra(a, b);

    cout << "Index of extra element in A: " << extraIndex << endl;
    cout << "Extra element: " << a[extraIndex] << endl;

    return 0;
}
