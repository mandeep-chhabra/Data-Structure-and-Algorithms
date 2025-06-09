#include <bits/stdc++.h>
using namespace std;

void checkKthBit(int n, int k)
{
    if ((n & (1 << k)) != 0)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

int main()
{
    int num, k;
    cin >> num >> k;
    checkKthBit(num, k);
    return 0;
}