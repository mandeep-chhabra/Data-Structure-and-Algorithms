#include <iostream>
#include <vector>
using namespace std;

int countBuildings(vector<int> &height)
{
    int max = height[0];
    int count = 1;
    for (int i = 1; i < height.size(); i++)
    {
        if (height[i] > max)
        {
            count++;
            max = height[i];
        }
    }
    return count;
}

int main()
{
    int n, x;
    vector<int> height;

    cout << "Enter the number of buildings: ";
    cin >> n;

    cout << "Enter the heights of the buildings:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        height.push_back(x);
    }

    int visible = countBuildings(height);

    cout << "Number of buildings visible from the left: " << visible << endl;

    return 0;
}
