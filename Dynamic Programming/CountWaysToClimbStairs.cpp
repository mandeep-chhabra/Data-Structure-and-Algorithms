#include <iostream>
#include <vector>

using namespace std;

int solve(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int countWays(int n)
{
    if (n < 0)
        return 0;
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

int main()
{
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Number of stairs must be non-negative." << endl;
        return 1;
    }

    cout << "Number of ways to climb " << n << " stairs: " << countWays(n) << endl;

    return 0;
}