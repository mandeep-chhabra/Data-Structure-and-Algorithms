#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &arr)
{
    if (arr.size() == 0)
        return 0;

    int i = 0;
    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[j] != arr[i])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int main()
{
    vector<int> arr;
    int n, x;

    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    cout << "Enter the sorted elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    int newSize = removeDuplicates(arr);

    cout << "Modified array with unique elements: ";
    for (int i = 0; i < newSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
