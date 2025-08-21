#include <iostream>
#include <vector>

using namespace std;

int transitionPoint(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid size." << endl;
        return 1;
    }

    vector<int> arr(size);
    cout << "Enter the elements (0s and 1s): ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    int result = transitionPoint(arr);

    if (result != -1)
    {
        cout << "The transition point is at index: " << result << endl;
    }
    else
    {
        cout << "There is no transition point." << endl;
    }

    return 0;
}