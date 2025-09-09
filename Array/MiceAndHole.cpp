#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int minTime(vector<int> &mices, vector<int> &holes)
{
    int n = mices.size();
    int res = 0;

    sort(mices.begin(), mices.end());
    sort(holes.begin(), holes.end());

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cnt = abs(holes[i] - mices[i]);
        res = max(res, cnt);
    }

    return res;
}

int main()
{
    int n;
    cout << "Enter the number of mice and holes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Time required is 0." << endl;
        return 0;
    }

    vector<int> mices(n);
    vector<int> holes(n);

    cout << "Enter the positions of the mice: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> mices[i];
    }

    cout << "Enter the positions of the holes: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> holes[i];
    }

    int result = minTime(mices, holes);

    cout << "Minimum time required for all mice to enter holes: " << result << endl;

    return 0;
}