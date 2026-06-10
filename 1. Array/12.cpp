// Rotate Matrix by 90 degrees
// Given an n x n 2D matrix, rotate it by 90 degrees (clockwise).
/*
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/



#include <bits/stdc++.h>
using namespace std;


// Brute force approach:- We can create a new matrix and copy the elements from the original matrix to the new matrix in the rotated position. This approach will take O(n*n) time complexity and O(n*n) space complexity.

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }

    matrix = rotated;
}

void rotateoptimal(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotateoptimal(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}