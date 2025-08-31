#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int n, vector<int> &arr, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = max(arr[n - 1] + solve(n - 2, arr, dp), solve(n - 1, arr, dp));
}

int findMaxSum(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;
    vector<int> dp(n + 1, -1);
    return solve(n, arr, dp);
}

int main()
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Max sum is 0." << endl;
        return 1;
    }

    vector<int> arr(size);
    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    int maxSum = findMaxSum(arr);
    cout << "The maximum sum of non-adjacent elements is: " << maxSum << endl;

    return 0;
}