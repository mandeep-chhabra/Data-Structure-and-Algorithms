#include <bits/stdc++.h>
using namespace std;

void oddOrEven(int n)
{
    (n & 1) ? cout << "odd" : cout << "even";
}

int main()
{
    int n;
    cin >> n;
    oddOrEven(n);
    return 0;
}