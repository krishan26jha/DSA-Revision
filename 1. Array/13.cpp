// print spiral matrix
/*
Example 1:  
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/  

#include <bits/stdc++.h>
using namespace std;

// optimal approach:- We can use four pointers to keep track of the boundaries of the matrix and
// traverse the matrix in a spiral manner. This approach will take O(m*n) time complexity and O(m*n) space complexity.

void printSpiralMatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> spiral;

    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) // we will keep traversing until the boundaries are valid
    {
        // Traverse from left to right
        for (int i = left; i <= right; i++)
            spiral.push_back(matrix[top][i]);
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++)
            spiral.push_back(matrix[i][right]);
        right--;

        if (top <= bottom) // it will valid till we have one row left to traverse
        {
            // Traverse from right to left
            for (int i = right; i >= left; i--)
                spiral.push_back(matrix[bottom][i]);
            bottom--;
        }

        if (left <= right) // it will valid till we have one column left to traverse
        {
            // Traverse from bottom to top
            for (int i = bottom; i >= top; i--)
                spiral.push_back(matrix[i][left]);
            left++;
        }
    }

    for (int num : spiral)
        cout << num << " ";
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printSpiralMatrix(matrix);
    return 0;
}