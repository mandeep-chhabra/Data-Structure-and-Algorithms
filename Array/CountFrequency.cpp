#include <iostream>
#include <vector>
using namespace std;

// Function to count frequency of target element in array
int countFreq(vector<int> &arr, int target)
{
    int freq = 0;
    for (auto it : arr)
    {
        if (it == target)
        {
            freq++;
        }
    }
    return freq;
}

// Main function to test the countFreq function
int main()
{
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target element to count: ";
    cin >> target;

    int frequency = countFreq(arr, target);
    cout << "Frequency of " << target << " is: " << frequency << endl;

    return 0;
}
