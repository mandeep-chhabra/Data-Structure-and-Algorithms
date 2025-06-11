#include <bits/stdc++.h>
using namespace std;

void setRightmostBit(int n)
{
    cout << (n | (n + 1));
}

int main()
{
    int n;
    cin >> n;
    setRightmostBit(n);
    return 0;
}