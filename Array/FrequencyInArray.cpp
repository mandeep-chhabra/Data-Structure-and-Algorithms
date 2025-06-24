#include <iostream>
#include <vector>
using namespace std;

vector<int> frequencyCount(vector<int> &arr)
{
    int size = arr.size();
    vector<int> result(size, 0);

    for (int it : arr)
    {
        if (it >= 1 && it <= size)
            result[it - 1]++;
    }

    return result;
}

int main()
{
    int n, x;
    vector<int> arr;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements (values should be in range 1 to " << n << "):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    vector<int> freq = frequencyCount(arr);

    cout << "Frequencies from 1 to " << n << ": ";
    for (int count : freq)
    {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
