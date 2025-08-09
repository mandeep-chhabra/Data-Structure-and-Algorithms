#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<int> &arr, int x)
{
    int l = 0, r = arr.size() - 1, ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter value of x: ";
    cin >> x;

    int floorIndex = findFloor(arr, x);

    if (floorIndex != -1)
        cout << "Floor of " << x << " is " << arr[floorIndex]
             << " at index " << floorIndex << endl;
    else
        cout << "No floor exists for " << x << " in the array." << endl;

    return 0;
}
