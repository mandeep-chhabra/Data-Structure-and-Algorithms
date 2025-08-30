#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

long long solve(int n, vector<long long> &dp)
{
    if (n == 0)
        return 2;
    if (n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = (solve(n - 1, dp) + solve(n - 2, dp)) % MOD;
}

long long lucas(int n)
{
    if (n < 0)
        return 0;
    vector<long long> dp(n + 1, -1);
    return solve(n, dp);
}

int main()
{
    int n;
    cout << "Enter the value of n to find the nth Lucas number: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Lucas numbers are defined for non-negative integers." << endl;
        return 1;
    }

    cout << "The " << n << "th Lucas number is: " << lucas(n) << endl;

    return 0;
}