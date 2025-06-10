#include <bits/stdc++.h>
using namespace std;

void checkPowerOf2(int n)
{
    !(n & (n - 1)) ? cout << "Power of 2" : cout << "Not a power of 2";
}

int main()
{
    int n;
    cin >> n;
    checkPowerOf2(n);
    return 0;
}