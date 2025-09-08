#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findPlatform(vector<int> arr, vector<int> dep)
{
    int res = 0;
    int n = arr.size();

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int j = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        while (j < n && dep[j] < arr[i])
        {
            cnt--;
            j++;
        }

        cnt++;

        res = max(res, cnt);
    }

    return res;
}

int main()
{
    int n;
    cout << "Enter the number of trains: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of platforms required is 0." << endl;
        return 0;
    }

    vector<int> arr(n);
    vector<int> dep(n);

    cout << "Enter arrival times: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter departure times: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> dep[i];
    }

    int platforms = findPlatform(arr, dep);

    cout << "Minimum number of platforms required: " << platforms << endl;

    return 0;
}