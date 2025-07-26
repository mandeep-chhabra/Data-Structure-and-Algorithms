#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &words)
{
    unordered_map<string, vector<string>> groups;

    for (const string &word : words)
    {
        string sorted_word = word;
        sort(sorted_word.begin(), sorted_word.end());
        groups[sorted_word].push_back(word);
    }

    vector<vector<string>> result;
    for (auto &entry : groups)
    {
        result.push_back(entry.second);
    }

    return result;
}

int main()
{
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> grouped = groupAnagrams(input);

    for (const auto &group : grouped)
    {
        for (const string &word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
