/*
QUESTION:-

Given an m x n integer matrix, if an element is 0, set its entire row and
column to 0. The change must be done in place.

Constraints:
1 <= m, n <= 200

Example 1:

Input:
matrix = [[1,1,1],[1,0,1],[1,1,1]]

Output:
[[1,0,1],[0,0,0],[1,0,1]]

Example 2:

Input:
matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]

Output:
[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

/*
APPROACH:-

-> Use the first row and the first column of the matrix as marker storage.
-> First remember whether the first row and the first column already contain a zero.
-> For every cell (i, j) with i >= 1 and j >= 1, if it is 0, mark matrix[i][0] and matrix[0][j] as 0.
-> In a second pass, set a cell to 0 if its row marker or its column marker is 0.
-> Finally, clear the first row and the first column only if they had a zero originally.
-> The first row and column are handled last so that the markers are not destroyed too early.
-> This avoids an extra row and column array, so no extra memory is needed.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int rows = (int)matrix.size();
    int cols = (int)matrix[0].size();
    bool firstRowHasZero = false;
    bool firstColHasZero = false;

    for (int j = 0; j < cols; j++)
    {
        if (matrix[0][j] == 0)
        {
            firstRowHasZero = true;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColHasZero = true;
        }
    }

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRowHasZero)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[0][j] = 0;
        }
    }

    if (firstColHasZero)
    {
        for (int i = 0; i < rows; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    setZeroes(matrix);

    for (int i = 0; i < (int)matrix.size(); i++)
    {
        for (int j = 0; j < (int)matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N * M)
SPACE COMPLEXITY = O(1)
*/
