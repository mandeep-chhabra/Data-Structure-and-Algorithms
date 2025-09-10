#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string largestSwap(string &s)
{
    char maxi = '0';
    int idx = -1;
    int l = -1, r = -1;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] > maxi)
        {
            maxi = s[i];
            idx = i;
        }
        else if (s[i] < maxi)
        {
            l = i;
            r = idx;
        }
    }

    if (l == -1)
        return s;

    swap(s[l], s[r]);
    return s;
}

int main()
{
    string s;
    cout << "Enter a string of digits: ";
    cin >> s;

    string result = largestSwap(s);

    cout << "The lexicographically largest string after one swap is: " << result << endl;

    return 0;
}