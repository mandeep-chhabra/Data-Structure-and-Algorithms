#include <iostream>
#include <vector>

using namespace std;

void fill(vector<vector<int>> &image, int sr, int sc, int newColor, int m, int n, int oldColor)
{
    if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != oldColor)
    {
        return;
    }

    image[sr][sc] = newColor;

    fill(image, sr - 1, sc, newColor, m, n, oldColor);
    fill(image, sr, sc - 1, newColor, m, n, oldColor);
    fill(image, sr + 1, sc, newColor, m, n, oldColor);
    fill(image, sr, sc + 1, newColor, m, n, oldColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    if (image[sr][sc] == newColor)
    {
        return image;
    }
    int m = image.size();
    int n = image[0].size();
    int oldColor = image[sr][sc];
    fill(image, sr, sc, newColor, m, n, oldColor);
    return image;
}

void printImage(const vector<vector<int>> &image)
{
    for (const auto &row : image)
    {
        for (int pixel : row)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> image(rows, vector<int>(cols));
    cout << "Enter the pixel values:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> image[i][j];
        }
    }

    int startRow, startCol, newColor;
    cout << "Enter the starting row (0-indexed): ";
    cin >> startRow;
    cout << "Enter the starting column (0-indexed): ";
    cin >> startCol;
    cout << "Enter the new color: ";
    cin >> newColor;

    cout << "Original Image:" << endl;
    printImage(image);

    vector<vector<int>> filledImage = floodFill(image, startRow, startCol, newColor);

    cout << "Image after Flood Fill:" << endl;
    printImage(filledImage);

    return 0;
}