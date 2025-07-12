#include <iostream>
#include <vector>
using namespace std;

int findEquilibrium(vector<int> &arr)
{
    int prefSum = 0, total = 0;

    for (int ele : arr)
    {
        total += ele;
    }

    for (int pivot = 0; pivot < arr.size(); pivot++)
    {
        int suffSum = total - prefSum - arr[pivot];
        if (prefSum == suffSum)
        {
            return pivot;
        }
        prefSum += arr[pivot];
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = findEquilibrium(arr);

    if (result == -1)
        cout << "No equilibrium index found." << endl;
    else
        cout << "Equilibrium index: " << result << endl;

    return 0;
}
