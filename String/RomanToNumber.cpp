#include <iostream>
#include <unordered_map>
using namespace std;

int romanToDecimal(string &s)
{
    unordered_map<char, int> mp;
    mp.insert({{'I', 1},
               {'V', 5},
               {'X', 10},
               {'L', 50},
               {'C', 100},
               {'D', 500},
               {'M', 1000}});
    int num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 < s.size() && mp[s[i]] < mp[s[i + 1]])
        {
            num += mp[s[i + 1]] - mp[s[i]];
            i++;
        }
        else
        {
            num += mp[s[i]];
        }
    }
    return num;
}

int main()
{
    string roman;
    cout << "Enter Roman numeral: ";
    cin >> roman;

    int decimalValue = romanToDecimal(roman);
    cout << "Decimal value: " << decimalValue << endl;

    return 0;
}
