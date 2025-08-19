#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rowWithMax1s(vector<vector<int>> &arr)
{
    int rowIndex = -1;
    int maxCount = 0;
    int R = arr.size();
    int C = arr[0].size();

    for (int i = 0; i < R; i++)
    {
        int count = 0;
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] == 1)
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            rowIndex = i;
        }
    }

    return rowIndex;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0)
    {
        cout << "Invalid dimensions." << endl;
        return 1;
    }

    vector<vector<int>> arr(rows, vector<int>(cols));
    cout << "Enter the matrix elements (0s and 1s):" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> arr[i][j];
        }
    }

    int result = rowWithMax1s(arr);

    if (result != -1)
    {
        cout << "The row with the maximum number of 1s is at index: " << result << endl;
    }
    else
    {
        cout << "No row contains any 1s." << endl;
    }

    return 0;
}