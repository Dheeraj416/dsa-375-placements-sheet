/*
QUESTION:-

You are given an n x n 2D matrix representing an image. Rotate the image by 90
degrees clockwise. The rotation must be done in place, so do not allocate
another 2D matrix.

Constraints:
1 <= n <= 20

Example 1:

Input:
matrix = [[1,2,3],[4,5,6],[7,8,9]]

Output:
[[7,4,1],[8,5,2],[9,6,3]]

Example 2:

Input:
matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]

Output:
[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/

/*
APPROACH:-

-> A 90 degree clockwise rotation is the same as a transpose followed by reversing every row.
-> Transpose means swapping matrix[i][j] with matrix[j][i] for all j > i.
-> After the transpose, reverse each row from left to right.
-> Only the upper triangle is visited while transposing, so no element is swapped twice.
-> All the swaps happen inside the same matrix, so no extra matrix is needed.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &matrix)
{
    int n = (int)matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotateMatrix(matrix);

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
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(1)
*/
