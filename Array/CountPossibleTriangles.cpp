#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findNumberOfTriangles(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;

    sort(arr.begin(), arr.end());

    for (int k = n - 1; k >= 2; k--)
    {
        int i = 0, j = k - 1;
        while (i < j)
        {
            if (arr[i] + arr[j] > arr[k])
            {
                count += (j - i);
                j--;
            }
            else
            {
                i++;
            }
        }
    }
    return count;
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
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    if (size < 3)
    {
        cout << "A minimum of 3 elements is required to form a triangle." << endl;
        return 1;
    }

    vector<int> arr(size);
    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    int triangleCount = findNumberOfTriangles(arr);

    cout << "The number of triangles that can be formed is: " << triangleCount << endl;

    return 0;
}