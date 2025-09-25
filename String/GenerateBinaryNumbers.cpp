#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string decimalToBinary(int n)
{
    string s = "";
    if (n == 0)
        return "0";
    while (n > 0)
    {
        s += (n % 2 == 0 ? '0' : '1');
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

vector<string> generateBinary(int n)
{
    vector<string> res;
    if (n == 0)
        return {"0"};
    for (int i = 1; i <= n; i++)
    {
        string s = decimalToBinary(i);
        res.push_back(s);
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Invalid input. Please enter a non-negative integer." << endl;
        return 1;
    }

    vector<string> binaryNumbers = generateBinary(n);

    cout << "Binary representations from 1 to " << n << ":" << endl;
    for (const string &bin : binaryNumbers)
    {
        cout << bin << endl;
    }

    return 0;
}