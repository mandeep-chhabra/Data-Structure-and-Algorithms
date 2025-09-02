#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int i, vector<int> &arr, vector<vector<int>> &res, vector<int> &subset)
{
    if (i == arr.size())
    {
        res.push_back(subset);
        return;
    }

    subset.push_back(arr[i]);
    solve(i + 1, arr, res, subset);

    subset.pop_back();
    solve(i + 1, arr, res, subset);
}

vector<vector<int>> subsets(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<int> subset;
    vector<vector<int>> res;
    solve(0, arr, res, subset);
    sort(res.begin(), res.end());
    return res;
}

void printSubsets(const vector<vector<int>> &res)
{
    cout << "{";
    for (const auto &subset : res)
    {
        cout << "{";
        for (int j = 0; j < subset.size(); ++j)
        {
            cout << subset[j] << (j == subset.size() - 1 ? "" : ",");
        }
        cout << "}";
    }
    cout << "}" << endl;
}

int main()
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "{}" << endl;
        return 0;
    }

    vector<int> arr(size);
    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    vector<vector<int>> result = subsets(arr);

    cout << "The subsets are: ";
    printSubsets(result);

    return 0;
}