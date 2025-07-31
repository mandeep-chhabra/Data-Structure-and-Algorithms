#include <iostream>
#include <vector>
using namespace std;

vector<int> findTwoElement(vector<int> &arr)
{
    int n = arr.size();
    long long S = (long long)n * (n + 1) / 2;               // sum of 1 to n
    long long P = (long long)n * (n + 1) * (2 * n + 1) / 6; // sum of squares 1 to n

    long long S_actual = 0, P_actual = 0;
    for (int num : arr)
    {
        S_actual += num;
        P_actual += (long long)num * num;
    }

    long long diff = S - S_actual;    // x - y
    long long diff_sq = P - P_actual; // x^2 - y^2

    long long sum_xy = diff_sq / diff; // x + y

    int x = (diff + sum_xy) / 2; // missing number
    int y = sum_xy - x;          // duplicate number

    return {y, x}; // {duplicate, missing}
}

int main()
{
    vector<int> arr = {3, 1, 3};

    vector<int> result = findTwoElement(arr);

    cout << "Duplicate: " << result[0] << ", Missing: " << result[1] << endl;

    return 0;
}
