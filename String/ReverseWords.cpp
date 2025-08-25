#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseWords(string &s)
{
    reverse(s.begin(), s.end());

    int n = s.size();
    int i = 0;
    for (int l = 0; l < n; ++l)
    {
        if (s[l] != '.')
        {
            if (i != 0)
                s[i++] = '.';
            int r = l;
            while (r < n && s[r] != '.')
                s[i++] = s[r++];

            reverse(s.begin() + i - (r - l), s.begin() + i);

            l = r;
        }
    }
    s.erase(s.begin() + i, s.end());
    return s;
}

int main()
{
    string inputString;
    cout << "Enter a string with words separated by dots: ";
    cin >> inputString;

    string reversed = reverseWords(inputString);

    cout << "The words reversed string is: " << reversed << endl;

    return 0;
}