#include <iostream>
#include <vector>

using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> &mat)
{
    int m = mat.size();
    if (m == 0)
    {
        return {};
    }
    int n = mat[0].size();
    vector<int> res;
    int top = 0, left = 0;
    int bottom = m - 1, right = n - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            res.push_back(mat[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            res.push_back(mat[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                res.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return res;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0)
    {
        cout << "Invalid dimensions." << endl;
        return 1;
    }

    vector<vector<int>> mat(rows, vector<int>(cols));
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> mat[i][j];
        }
    }

    vector<int> result = spirallyTraverse(mat);

    cout << "Spiral Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}