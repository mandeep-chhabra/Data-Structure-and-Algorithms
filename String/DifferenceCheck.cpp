#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

int minDifference(vector<string> &arr) {
    vector<int> timesInSeconds;

    for (const auto& timeStr : arr) {
        int hours = stoi(timeStr.substr(0, 2));
        int minutes = stoi(timeStr.substr(3, 2));
        int seconds = stoi(timeStr.substr(6, 2));
        timesInSeconds.push_back(hours * 3600 + minutes * 60 + seconds);
    }

    sort(timesInSeconds.begin(), timesInSeconds.end());

    int minDiff = INT_MAX;
    for (size_t i = 0; i < timesInSeconds.size() - 1; ++i) {
        minDiff = min(minDiff, timesInSeconds[i + 1] - timesInSeconds[i]);
    }

    // Wrap-around difference (from last to first, over midnight)
    int wrapAroundDiff = (24 * 3600) - (timesInSeconds.back() - timesInSeconds.front());
    minDiff = min(minDiff, wrapAroundDiff);

    return minDiff;
}

int main() {
    int n;
    cout << "Enter number of time strings: ";
    cin >> n;

    vector<string> arr(n);
    cout << "Enter the time strings in HH:MM:SS format:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = minDifference(arr);
    cout << "Minimum difference in seconds: " << result << endl;

    return 0;
}
