#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

char nonRepeatingChar(string &s)
{
    unordered_map<char, int> mp;
    for (char c : s)
    {
        mp[c]++;
    }

    for (char c : s)
    {
        if (mp[c] == 1)
        {
            return c;
        }
    }
    return '$';
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    char result = nonRepeatingChar(s);

    if (result != '$')
    {
        cout << "The first non-repeating character is: " << result << endl;
    }
    else
    {
        cout << "No non-repeating character found." << endl;
    }

    return 0;
}