#include <iostream>
#include <vector>
using namespace std;

bool arraySortedOrNot(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, x;
    vector<int> arr;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    if (arraySortedOrNot(arr))
    {
        cout << "Sorted" << endl;
    }
    else
    {
        cout << "Not Sorted" << endl;
    }

    return 0;
}
