#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstRepeated(vector<int> &arr)
{
    unordered_map<int, int> freq;
    for (int num : arr)
    {
        freq[num]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (freq[arr[i]] > 1)
        {
            return i + 1;
        }
    }

    return -1;
}

int main()
{
    int n, x;
    vector<int> arr;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    int result = firstRepeated(arr);

    if (result == -1)
        cout << "No repeated elements found." << endl;
    else
        cout << "First repeated element is at position (1-based): " << result << endl;

    return 0;
}
