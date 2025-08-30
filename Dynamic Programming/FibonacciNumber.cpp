#include <iostream>
#include <vector>

using namespace std;

int solve(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int nthFibonacci(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

int main()
{
    int n;
    cout << "Enter the value of n to find the nth Fibonacci number: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Fibonacci numbers are defined for non-negative integers." << endl;
        return 1;
    }

    cout << "The " << n << "th Fibonacci number is: " << nthFibonacci(n) << endl;

    return 0;
}