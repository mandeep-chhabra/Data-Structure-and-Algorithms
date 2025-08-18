#include <iostream>
#include <vector>

using namespace std;

int peakElement(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr.size() == 1)
        {
            return i;
        }
        if (i == 0)
        {
            if (arr[i] > arr[i + 1])
            {
                return i;
            }
        }
        else if (i == arr.size() - 1)
        {
            if (arr[i] > arr[i - 1])
            {
                return i;
            }
        }
        else
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid size." << endl;
        return 0;
    }

    vector<int> arr(size);
    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    int peakIndex = peakElement(arr);

    if (peakIndex != -1)
    {
        cout << "A peak element is found at index " << peakIndex << " with value " << arr[peakIndex] << endl;
    }
    else
    {
        cout << "No peak element found." << endl;
    }

    return 0;
}