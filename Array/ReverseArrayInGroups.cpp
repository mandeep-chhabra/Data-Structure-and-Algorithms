#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverseInGroups(vector<int> &arr, int k)
{
    if (arr.size() < k)
    {
        reverse(arr.begin(), arr.end());
        return;
    }
    int start = 0;
    int end = k;
    int n = (arr.size() + k - 1) / k;
    for (int i = 0; i < n; i++)
    {
        reverse(arr.begin() + start, arr.begin() + end);
        start += k;
        end += k;
        if (end > arr.size())
        {
            end = arr.size();
        }
    }
}

void printVector(const vector<int> &arr)
{
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int size, k;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid size." << endl;
        return 1;
    }

    vector<int> arr(size);
    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter the group size (k): ";
    cin >> k;

    cout << "Original array: ";
    printVector(arr);

    reverseInGroups(arr, k);

    cout << "Array after reversing in groups of " << k << ": ";
    printVector(arr);

    return 0;
}