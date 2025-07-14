#include <iostream>
#include <vector>
using namespace std;

int findRotationCount(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        // Case when the subarray is already sorted
        if (arr[low] <= arr[high])
            return low;

        int mid = low + (high - low) / 2;
        int next = (mid + 1) % arr.size();
        int prev = (mid - 1 + arr.size()) % arr.size();

        // Check if mid is the minimum
        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
            return mid;

        // Go to the unsorted half
        if (arr[mid] >= arr[low])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0; // fallback
}

int main()
{
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    int index = findRotationCount(arr);
    cout << "Array is rotated " << index << " times." << endl;
    return 0;
}
