#include <bits/stdc++.h>
using namespace std;

void countSetBits(int n)
{
    int cnt = 0;
    while (n > 1)
    {
        if (n % 2 == 1)
            cnt++;
        n = n / 2;
    }
    if (n == 1)
        cnt++;
    cout << "Set Bits: " << cnt << endl;
}

int main()
{
    int n;
    cin >> n;
    countSetBits(n);
    return 0;
}