#include <iostream>
#include <vector>

using namespace std;

// int solve(int n, vector<int> &dp){
//     if(n <= 1) return n;
//     if(n == 2) return 1;
//
//     if(dp[n] != -1) return dp[n];
//
//     return dp[n] = solve(n-1, dp) + solve(n-2, dp) + solve(n-3, dp);
// }

// int nthTribonacci(int n) {
//     vector<int> dp(n+1, -1);
//     return solve(n, dp);
// }

int nthTribonacci(int n)
{
    if (n <= 1)
        return n;
    if (n == 2)
        return 1;

    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the value of n to find the nth Tribonacci number: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Tribonacci numbers are defined for non-negative integers." << endl;
        return 1;
    }

    cout << "The " << n << "th Tribonacci number is: " << nthTribonacci(n) << endl;

    return 0;
}