#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool areAnagrams(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;

    cout << "Enter the second string: ";
    cin >> s2;

    bool result = areAnagrams(s1, s2);

    if (result)
    {
        cout << "The strings are anagrams." << endl;
    }
    else
    {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}