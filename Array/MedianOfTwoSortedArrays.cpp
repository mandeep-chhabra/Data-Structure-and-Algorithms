#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double medianOf2(vector<int> &a, vector<int> &b)
{
    int m = a.size();
    int n = b.size();

    int total = m + n;
    int medianIdx1 = (total + 1) / 2;
    int medianIdx2 = (total % 2 == 0) ? (total / 2 + 1) : medianIdx1;
    int i = 0, j = 0, count = 0;
    int curr = 0, prev = 0;

    while (count < medianIdx2)
    {
        prev = curr;
        if (i < m && (j >= n || a[i] <= b[j]))
        {
            curr = a[i++];
        }
        else
        {
            curr = b[j++];
        }
        count++;
    }

    if (total % 2 == 0)
    {
        return (prev + curr) / 2.0;
    }
    else
    {
        return curr;
    }
}

void getSortedVector(vector<int> &arr, int size, string prompt)
{
    cout << prompt;
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
}

int main()
{
    int sizeA, sizeB;
    cout << "Enter size of first sorted array: ";
    cin >> sizeA;
    vector<int> a(sizeA);
    getSortedVector(a, sizeA, "Enter elements of first array (will be sorted): ");

    cout << "Enter size of second sorted array: ";
    cin >> sizeB;
    vector<int> b(sizeB);
    getSortedVector(b, sizeB, "Enter elements of second array (will be sorted): ");

    cout << "First array: ";
    for (int val : a)
        cout << val << " ";
    cout << endl;

    cout << "Second array: ";
    for (int val : b)
        cout << val << " ";
    cout << endl;

    double median = medianOf2(a, b);
    cout << "The median of the two sorted arrays is: " << median << endl;

    return 0;
}