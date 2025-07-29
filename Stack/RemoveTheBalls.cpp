#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int findLength(vector<int> &color, vector<int> &radius)
{
    stack<int> st1;
    stack<int> st2;
    for (int i = 0; i < color.size(); i++)
    {
        if (st1.empty() || !(st1.top() == color[i] && st2.top() == radius[i]))
        {
            st1.push(color[i]);
            st2.push(radius[i]);
        }
        else
        {
            st1.pop();
            st2.pop();
        }
    }
    return (int)st1.size();
}

int main()
{
    int n;
    cout << "Enter number of balls: ";
    cin >> n;

    vector<int> color(n), radius(n);
    cout << "Enter " << n << " colors: ";
    for (int i = 0; i < n; ++i)
        cin >> color[i];

    cout << "Enter " << n << " radii: ";
    for (int i = 0; i < n; ++i)
        cin >> radius[i];

    int ans = findLength(color, radius);
    cout << "Remaining length: " << ans << endl;

    return 0;
}
