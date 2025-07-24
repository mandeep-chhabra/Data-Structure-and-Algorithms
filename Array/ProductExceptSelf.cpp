#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &arr)
{
    int product = 1;
    int zeros = 0;
    int index;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            zeros++;
            index = i;
        }
        else
        {
            product *= arr[i];
        }
    }

    vector<int> res(arr.size(), 0);
    if (zeros == 0)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            res[i] = product / arr[i];
        }
    }
    else if (zeros == 1)
    {
        res[index] = product;
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(arr);

    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}
