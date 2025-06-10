#include <bits/stdc++.h>
using namespace std;

void setKthBit(int n, int k)
{
    cout << (n | (1 << k));
}

int main()
{
    int n, k;
    cin >> n >> k;
    setKthBit(n, k);
    return 0;
}