//SET MATRIX ZEROES
// Given an m x n integer matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place. 
/*
Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/

// Brute force approach:- We can iterate through the matrix  and whenever we find a 0, we can marks its rows and colmn elements as -1. 
// Then we can iterate through the matrix again and replace all the -1 with 0. This approach will take O(m*n) time complexity and O(1) space complexity.

//code :
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < n; k++)
                {
                    if (matrix[i][k] != 0)
                        matrix[i][k] = -1;
                }
                for (int k = 0; k < m; k++)
                {
                    if (matrix[k][j] != 0)
                        matrix[k][j] = -1;
                }
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }
}

// T.C : O(m*n)(n+m) + O(m*n)


// Better : We can use two one dimensional arrays to keep track of the rows and columns that need to be set to 0.
// We can iterate through the matrix and whenever we find a 0, we can mark its row and column in the respective arrays.
// Then we can iterate through the matrix again and set the elements to 0 if their row or column is marked. 
// This approach will take O(m*n) time complexity and O(m+n) space complexity.

#include <bits/stdc++.h>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> rows(m, 0);
    vector<int> cols(n, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rows[i] == 1 || cols[j] == 1)
                matrix[i][j] = 0;
        }
    }
}

// Optimal : 
// We can use colmn array (col[0]) and row array (row[0]) inside the matrix itself to keep track of the rows and columns that need to be set to 0.
// but we need to make a col0 variable for removing the ambiguity of the first cell of the matrix.
// We can iterate through the matrix and whenever we find a 0, we can mark its row and column in the respective arrays.
// Then we can iterate through the matrix again and set the elements to 0 if their row or column is marked.
// for the first row and first column we can check the col0 variable and row[0] variable respectively.
// we will not hamper the first row and first column because we are using them to keep track of the rows and columns that need to be set to 0.
// after all the remaining elements are set to 0, we should first try to set the first row to 0 and then the first column to 0
// because if we set the first column to 0 first,bcs first row elements is depending on itself and column[0], 
// if we set the first column first then it will change the column[0], which will affect the first row elements and we will not be able to set the first row to 0 correctly.
// This approach will take O(m*n) time complexity and O(1) space complexity.


// code :

#include <bits/stdc++.h>
using namespace std;

void setMatrixZeroesOptimal(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int col0 = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
 

    // we will not hamper the first row and first column because we are using them to keep track of the rows and columns that need to be set to 0.
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if (matrix[0][0] == 0)
    {
        // set first row[0] to 0
        for (int j = 1; j < n; j++)
            matrix[0][j] = 0;
    }

    if (col0 == 0)
    {
        // set first column to 0
        for (int i = 1; i < m; i++)
            matrix[i][0] = 0;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setMatrixZeroesOptimal(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
