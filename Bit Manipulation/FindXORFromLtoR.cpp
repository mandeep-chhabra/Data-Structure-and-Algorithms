#include <bits/stdc++.h>
using namespace std;

int findXOR(int n)
{

    if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else if (n % 4 == 3)
        return 0;
    else
        return n;
}

int findXOR(int l, int r)
{
    return findXOR(l - 1) ^ findXOR(r);
}

int main()
{
    int l, r;
    cin >> l >> r;
    int res = findXOR(l, r);
    cout << res;
    return 0;
}